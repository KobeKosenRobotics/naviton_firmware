#ifndef _ROS_toio_lecture_Note_h
#define _ROS_toio_lecture_Note_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace toio_lecture
{

  class Note : public ros::Msg
  {
    public:
      typedef int32_t _note_type;
      _note_type note;
      typedef int32_t _volume_type;
      _volume_type volume;
      typedef int32_t _length_type;
      _length_type length;
      enum { C4 =  48 };
      enum { D4 =  50 };
      enum { E4 =  52 };
      enum { F4 =  53 };
      enum { G4 =  55 };
      enum { A4 =  57 };
      enum { B4 =  59 };
      enum { C5 =  60 };

    Note():
      note(0),
      volume(0),
      length(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_note;
      u_note.real = this->note;
      *(outbuffer + offset + 0) = (u_note.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_note.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_note.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_note.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->note);
      union {
        int32_t real;
        uint32_t base;
      } u_volume;
      u_volume.real = this->volume;
      *(outbuffer + offset + 0) = (u_volume.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_volume.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_volume.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_volume.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->volume);
      union {
        int32_t real;
        uint32_t base;
      } u_length;
      u_length.real = this->length;
      *(outbuffer + offset + 0) = (u_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->length);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_note;
      u_note.base = 0;
      u_note.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_note.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_note.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_note.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->note = u_note.real;
      offset += sizeof(this->note);
      union {
        int32_t real;
        uint32_t base;
      } u_volume;
      u_volume.base = 0;
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_volume.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->volume = u_volume.real;
      offset += sizeof(this->volume);
      union {
        int32_t real;
        uint32_t base;
      } u_length;
      u_length.base = 0;
      u_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->length = u_length.real;
      offset += sizeof(this->length);
     return offset;
    }

    const char * getType(){ return "toio_lecture/Note"; };
    const char * getMD5(){ return "ae4fcb55995a71a7243eae7fee7348f6"; };

  };

}
#endif