#ifndef _ROS_SERVICE_LoadOffset_h
#define _ROS_SERVICE_LoadOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotis_controller_msgs
{

static const char LOADOFFSET[] = "robotis_controller_msgs/LoadOffset";

  class LoadOffsetRequest : public ros::Msg
  {
    public:
      typedef const char* _file_path_type;
      _file_path_type file_path;

    LoadOffsetRequest():
      file_path("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_file_path = strlen(this->file_path);
      varToArr(outbuffer + offset, length_file_path);
      offset += 4;
      memcpy(outbuffer + offset, this->file_path, length_file_path);
      offset += length_file_path;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_file_path;
      arrToVar(length_file_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_path-1]=0;
      this->file_path = (char *)(inbuffer + offset-1);
      offset += length_file_path;
     return offset;
    }

    const char * getType(){ return LOADOFFSET; };
    const char * getMD5(){ return "a1f82596372c52a517e1fe32d1e998e8"; };

  };

  class LoadOffsetResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    LoadOffsetResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return LOADOFFSET; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class LoadOffset {
    public:
    typedef LoadOffsetRequest Request;
    typedef LoadOffsetResponse Response;
  };

}
#endif
