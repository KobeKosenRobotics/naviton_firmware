#include "NavitonROS.h"

NavitonROS::NavitonROS() : 
    Naviton(),
    _cmd_vel_sub(CMD_VEL_TOPIC, &NavitonROS::cmd_vel_cb, this)
{
    
}

void NavitonROS::Init(ros::NodeHandle& nh)
{
    Naviton::Init();
    nh.subscribe(_cmd_vel_sub);
}

void NavitonROS::Update()
{
    Naviton::Update();
}

void NavitonROS::cmd_vel_cb(const geometry_msgs::Twist& cmd_vel)
{
    if(!use_cmd_vel) return;
    _drive.Drive(cmd_vel.linear.x, cmd_vel.angular.z);
}