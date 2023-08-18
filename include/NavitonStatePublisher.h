#ifndef NAVITON_STATE_PUBLISHER_H
#define NAVITON_STATE_PUBLISHER_H

#include <ros.h>
#include <geometry_msgs/>
#include <RosArrayPublisher.h>

class NavitonStatePublisher
{
    private:
        RosArrayPublisher _publisher;
    public:
        NavitonStatePublisher();
        NavitonStatePublisher(ros::NodeHandle& nh,const char *topic_name);
        void Publish();
};

#endif