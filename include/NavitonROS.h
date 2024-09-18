/// @file   NavitonROS.h
/// @brief
/// @date   2023.07.19
/// @author Akiro Harada

#ifndef NAVITON_ROS_H
#define NAVITON_ROS_H

#include <geometry_msgs/Twist.h>
#include <ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Bool.h>

#include "config/RosParams.h"

#include "Naviton.h"
#include "NavitonStatePublisher.h"

class NavitonROS : Naviton {
private:
  NavitonStatePublisher _state_pub;
  ros::Subscriber<geometry_msgs::Twist, NavitonROS> _cmd_vel_sub;
  ros::Subscriber<geometry_msgs::Twist, NavitonROS> _remote_vel_sub;
  ros::Subscriber<std_msgs::Int32, NavitonROS> _remote_mode_sub;
  geometry_msgs::Twist _cmd_vel;
  geometry_msgs::Twist _remote_vel;
  std_msgs::Int32 _remote_mode;

public:
  NavitonROS();
  void Init(ros::NodeHandle &nh);
  void Update();
  void UpdateInput();

  void cmd_vel_cb(const geometry_msgs::Twist &twist);
  void remote_vel_cb(const geometry_msgs::Twist &twist);
  void remote_mode_cb(const std_msgs::Int32 &remote_mode);
};

#endif