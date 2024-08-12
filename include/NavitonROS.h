/// @file   NavitonROS.h
/// @brief
/// @date   2023.07.19
/// @author Akiro Harada

#ifndef NAVITON_ROS_H
#define NAVITON_ROS_H

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Bool.h>

#include "config/RosParams.h"

#include "Naviton.h"
#include "NavitonStatePublisher.h"

class NavitonROS : Naviton
{
    private:
        NavitonStatePublisher _state_pub;
        ros::Subscriber<geometry_msgs::Twist, NavitonROS> _cmd_vel_sub;
        ros::Subscriber<geometry_msgs::Twist, NavitonROS> _remote_vel_sub;
        ros::Subscriber<std_msgs::Bool, NavitonROS> _remote_cmd_sub;
        geometry_msgs::Twist _cmd_vel;
        geometry_msgs::Twist _remote_vel;
        std_msgs::Bool _remote_cmd;
    public:
        NavitonROS();
        void Init(ros::NodeHandle& nh);
        void Update();
        void UpdateInput();

        void cmd_vel_cb(const geometry_msgs::Twist& twist);
        void remote_vel_cb(const geometry_msgs::Twist& twist);
        void remote_cmd_cb(const std_msgs::Bool& remote_cmd);
};

#endif