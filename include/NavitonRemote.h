/// @file   NavitonROS.h
/// @brief
/// @date   2024.09.19
/// @author Soshiro Maruoka

#ifndef NAVITON_REMOTE_H
#define NAVITON_REMOTE_H

#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>

#include "NavitonROS.h"
#include "Naviton.h"

class NavitonRemote : NavitonROS {
private:
  ros::Subscriber<geometry_msgs::Twist, NavitonRemote> _remote_vel_sub;
  ros::Subscriber<std_msgs::Bool, NavitonRemote> _remote_emg_sub;
  ros::Subscriber<std_msgs::Int32, NavitonRemote> _remote_mode_sub;
  geometry_msgs::Twist _remote_vel;
  std_msgs::Bool _remote_emg;
  std_msgs::Int32 _remote_mode;

public:
  NavitonRemote();
  void Init(ros::NodeHandle &nh);
  void Update();
  void UpdateInput();

  void remote_vel_cb(const geometry_msgs::Twist &remote_vel);
  void remote_emg_cb(const std_msgs::Bool &remote_emg);
  void remote_mode_cb(const std_msgs::Int32 &remote_mode);
};

#endif
