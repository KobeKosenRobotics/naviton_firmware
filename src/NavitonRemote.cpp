#include "NavitonRemote.h"

NavitonRemote::NavitonRemote() :
    NavitonROS(),
    _remote_vel_sub(REMOTE_VEL_TOPIC, &NavitonRemote::remote_vel_cb, this),
    _remote_emg_sub(REMOTE_EMG_TOPIC, &NavitonRemote::remote_emg_cb, this),
    _remote_mode_sub(REMOTE_MODE_TOPIC, &NavitonRemote::remote_mode_cb, this)
{
}

void NavitonRemote::Init(ros::NodeHandle& nh)
{
    NavitonROS::Init(nh);

    _remote_mode.data = 0;
}

void NavitonRemote::Update()
{
    NavitonROS::Update();
}

void NavitonRemote::UpdateInput()
{
    if(digitalRead(MANUAL_SWITCH_PIN))
    {
        if(_remote_emg.data)
        {
            if(_remote_mode.data == 1)
            {
                // Remote
                _drive.Drive(_remote_vel.linear.x, _remote_vel.angular.z);
            }
            else
            {
                // Auto
                NavitonROS::UpdateInput();
            }
        }
        else
        {
            _drive.Stop();
        }
    }
    else
    {
        // Manual
        Naviton::UpdateInput();
    }
}

void NavitonRemote::remote_vel_cb(const geometry_msgs::Twist& remote_vel)
{
    _remote_vel = remote_vel;
}

void NavitonRemote::remote_emg_cb(const std_msgs::Bool& remote_emg)
{
    _remote_emg = remote_emg;
}

void NavitonRemote::remote_mode_cb(const std_msgs::Int32& remote_mode)
{
    _remote_mode = remote_mode;
}
