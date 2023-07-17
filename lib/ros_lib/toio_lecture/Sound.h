#ifndef _ROS_toio_lecture_Sound_h
#define _ROS_toio_lecture_Sound_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "toio_lecture/Note.h"

namespace toio_lecture
{

  class Sound : public ros::Msg
  {
    public:
      typedef int32_t _mode_type;
      _mode_type mode;
      typedef int32_t _effect_id_type;
      _effect_id_type effect_id;
      typedef int32_t _volume_type;
      _volume_type volume;
      uint32_t notes_length;
      typedef toio_lecture::Note _notes_type;
      _notes_type st_notes;
      _notes_type * notes;
      enum { EFFECT_SOUND =  2 };
      enum { MIDI =  3 };

    Sound():
      mode(0),
      effect_id(0),
      volume(0),
      notes_length(0), notes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        int32_t real;
        uint32_t base;
      } u_effect_id;
      u_effect_id.real = this->effect_id;
      *(outbuffer + offset + 0) = (u_effect_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_effect_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_effect_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_effect_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effect_id);
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
      *(outbuffer + offset + 0) = (this->notes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->notes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->notes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->notes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->notes_length);
      for( uint32_t i = 0; i < notes_length; i++){
      offset += this->notes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
      union {
        int32_t real;
        uint32_t base;
      } u_effect_id;
      u_effect_id.base = 0;
      u_effect_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_effect_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_effect_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_effect_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->effect_id = u_effect_id.real;
      offset += sizeof(this->effect_id);
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
      uint32_t notes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      notes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      notes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      notes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->notes_length);
      if(notes_lengthT > notes_length)
        this->notes = (toio_lecture::Note*)realloc(this->notes, notes_lengthT * sizeof(toio_lecture::Note));
      notes_length = notes_lengthT;
      for( uint32_t i = 0; i < notes_length; i++){
      offset += this->st_notes.deserialize(inbuffer + offset);
        memcpy( &(this->notes[i]), &(this->st_notes), sizeof(toio_lecture::Note));
      }
     return offset;
    }

    const char * getType(){ return "toio_lecture/Sound"; };
    const char * getMD5(){ return "7ffd3d62625a5f26beb036f32c7d61f3"; };

  };

}
#endif