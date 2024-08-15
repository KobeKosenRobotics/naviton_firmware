#include "NavitonROS.h"

NavitonROS::NavitonROS() :
    Naviton(),
    _state_pub(STATE_TOPIC),
    _cmd_vel_sub(CMD_VEL_TOPIC, &NavitonROS::cmd_vel_cb, this),
    _remote_vel_sub(REMOTE_VEL_TOPIC, &NavitonROS::remote_vel_cb, this),
    _remote_cmd_sub(REMOTE_CMD_TOPIC, &NavitonROS::remote_cmd_cb, this)
{
}

void NavitonROS::Init(ros::NodeHandle& nh)
{
    Naviton::Init();
    _state_pub.Init(nh);

    pinMode(AUTO_SWITCH_PIN, INPUT_PULLUP);

    _remote_cmd.data = 0;

    nh.subscribe(_cmd_vel_sub);
}

void NavitonROS::Update()
{
    Naviton::Update();

    _state_pub.SetPosition(_odom.GetX(), _odom.GetY(), _odom.GetZ());
    _state_pub.SetRotation(_gyro.GetW(), _gyro.GetX(), _gyro.GetY(), _gyro.GetZ());

    _state_pub.SetLocalVelocity(_drive.GetLinearVelocity(), _drive.GetAngularVelocity());

    _state_pub.Publish();
}

void NavitonROS::UpdateInput()
{
    if(digitalRead(EMERGENCY_STOP_PIN))
    {
        if(!digitalRead(AUTO_SWITCH_PIN))
        {
            if(_remote_cmd.data)
            {
                // Remote
                _drive.Drive(_remote_vel.linear.x, _remote_vel.angular.z);
            }
            else
            {
                // Auto
                _drive.Drive(_cmd_vel.linear.x, _cmd_vel.angular.z);
            }
        }
        else
        {
            // Manual
            Naviton::UpdateInput();
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

void NavitonROS::remote_vel_cb(const geometry_msgs::Twist& remote_vel)
{
    _remote_vel = remote_vel;
}

void NavitonROS::remote_cmd_cb(const std_msgs::Bool& remote_cmd)
{
    _remote_cmd = remote_cmd;
}