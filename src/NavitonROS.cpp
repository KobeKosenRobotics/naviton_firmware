#include "NavitonROS.h"

NavitonROS::NavitonROS() :
    Naviton(),
    _state_pub(STATE_TOPIC),
    _cmd_vel_sub(CMD_VEL_TOPIC, &NavitonROS::cmd_vel_cb, this)
{
}

void NavitonROS::Init(ros::NodeHandle& nh)
{
    Naviton::Init();
    _state_pub.Init(nh);

    pinMode(AUTO_MANUAL_SWITCH_PIN, INPUT_PULLUP);

    nh.subscribe(_cmd_vel_sub);
}

void NavitonROS::Update()
{
    Naviton::Update();

    _state_pub.SetPosition(_odom.GetX(), _odom.GetY(), _odom.GetZ());
    _state_pub.SetRotation(_gyro.GetW(), _gyro.GetX(), _gyro.GetY(), _gyro.GetZ());

    _state_pub.SetWheelVelocity(_drive.GetLeftWheelVelocity(), _drive.GetRightWheelVelocity());

    _state_pub.Publish();
}

void NavitonROS::UpdateInput()
{
    if(digitalRead(EMERGENCY_STOP_PIN))
    {
        if(digitalRead(AUTO_MANUAL_SWITCH_PIN))
        {
            // Auto
            _drive.Drive(_cmd_vel.linear.x, _cmd_vel.angular.z);
        }
        else
        {
            // Manual
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