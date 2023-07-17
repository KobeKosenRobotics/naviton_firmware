#ifndef _ROS_SERVICE_GetKinematicsPose_h
#define _ROS_SERVICE_GetKinematicsPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace manipulator_h_base_module_msgs
{

static const char GETKINEMATICSPOSE[] = "manipulator_h_base_module_msgs/GetKinematicsPose";

  class GetKinematicsPoseRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;

    GetKinematicsPoseRequest():
      group_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
     return offset;
    }

    const char * getType(){ return GETKINEMATICSPOSE; };
    const char * getMD5(){ return "967d0b0c0d858ded8a6a69abbce0c981"; };

  };

  class GetKinematicsPoseResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _group_pose_type;
      _group_pose_type group_pose;

    GetKinematicsPoseResponse():
      group_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->group_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->group_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETKINEMATICSPOSE; };
    const char * getMD5(){ return "9875670870ab7d344c5b4fd121c9797f"; };

  };

  class GetKinematicsPose {
    public:
    typedef GetKinematicsPoseRequest Request;
    typedef GetKinematicsPoseResponse Response;
  };

}
#endif
