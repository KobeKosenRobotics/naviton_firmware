#ifndef _ROS_basic_lecture_cmsg_h
#define _ROS_basic_lecture_cmsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace basic_lecture
{

  class cmsg : public ros::Msg
  {
    public:
      typedef const char* _word_type;
      _word_type word;
      typedef int32_t _number_type;
      _number_type number;

    cmsg():
      word(""),
      number(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_word = strlen(this->word);
      varToArr(outbuffer + offset, length_word);
      offset += 4;
      memcpy(outbuffer + offset, this->word, length_word);
      offset += length_word;
      union {
        int32_t real;
        uint32_t base;
      } u_number;
      u_number.real = this->number;
      *(outbuffer + offset + 0) = (u_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_word;
      arrToVar(length_word, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_word; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_word-1]=0;
      this->word = (char *)(inbuffer + offset-1);
      offset += length_word;
      union {
        int32_t real;
        uint32_t base;
      } u_number;
      u_number.base = 0;
      u_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number = u_number.real;
      offset += sizeof(this->number);
     return offset;
    }

    const char * getType(){ return "basic_lecture/cmsg"; };
    const char * getMD5(){ return "f9d86ff4272085f66f41cd72b9cfc49d"; };

  };

}
#endif