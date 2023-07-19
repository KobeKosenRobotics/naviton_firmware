#include "NavitonROS.h"

NavitonROS::NavitonROS() : 
    Naviton(),
    _cmd_vel_sub(CMD_VEL_TOPIC, &NavitonROS::cmd_vel_cb, this)
{
    
}

void NavitonROS::Init(ros::NodeHandle& nh)
{
    Naviton::Init();
    pinMode(AUTO_MANUAL_SWITCH_PIN, INPUT_PULLUP);
    nh.subscribe(_cmd_vel_sub);
}

void NavitonROS::Update()
{
    Naviton::Update();
}

void NavitonROS::UpdateInput()
{
    if(digitalRead(EMERGENCY_STOP_PIN))
    {
        if(digitalRead(AUTO_MANUAL_SWITCH_PIN))
        {
            
        }
        else
        {

        }
    }
    else
    {
        _drive.Stop();
    }
}

void NavitonROS::cmd_vel_cb(const geometry_msgs::Twist& cmd_vel)
{
    _cmd_vel = cmd_vel;
}