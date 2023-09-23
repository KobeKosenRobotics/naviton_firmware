#ifndef NAVITON_STATE_PUBLISHER_H
#define NAVITON_STATE_PUBLISHER_H

#include <ros.h>
#include <RosArrayPublisher.h>

class NavitonStatePublisher
{
    private:
        RosArrayPublisher<std_msgs::Float32MultiArray> _publisher;
    public:
        NavitonStatePublisher();
        NavitonStatePublisher(const char *topic_name);
        
        void Init(ros::NodeHandle& nh);
        void Publish();

        void SetPosition(double x, double y, double z);
        void SetRotation(double w, double x, double y, double z);
        void SetWheelVelocity(double left, double right);
};

#endif