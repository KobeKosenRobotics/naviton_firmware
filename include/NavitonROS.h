#ifndef NAVITON_ROS_H
#define NAVITON_ROS_H

#include <ros.h>
#include <geometry_msgs/Twist.h>

#include "config/RosParams.h"

#include "Naviton.h"

class NavitonROS : Naviton
{
    private:
        ros::Subscriber<geometry_msgs::Twist, NavitonROS> _cmd_vel_sub;
    public:
        NavitonROS();
        void Init(ros::NodeHandle& nh);
        void Update();

        void cmd_vel_cb(const geometry_msgs::Twist& twist);

        bool use_cmd_vel;
};

#endif