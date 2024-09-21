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

    _remote_emg.data = true;
    _remote_mode.data = 0;

    nh.subscribe(_remote_vel_sub);
    nh.subscribe(_remote_emg_sub);
    nh.subscribe(_remote_mode_sub);
}

void NavitonRemote::Update()
{
    NavitonROS::Update();
}

void NavitonRemote::UpdateInput()
{
    if(digitalRead(EMERGENCY_STOP_PIN))
    {
        if(!digitalRead(AUTO_SWITCH_PIN))
        {
            if(_remote_emg.data)
            {
                if(_remote_mode.data == 1)
                {
                    // Remote
                    double linear_vel = 0.0;
                    double angular_vel = 0.0;
                    double linear_vel_rate = (double)_remote_vel.linear.x;
                    double angular_vel_rate = (double)_remote_vel.angular.z;

                    linear_vel = abs(linear_vel_rate) >= JOY_DEAD_ZONE_PERCENTAGE ? linear_vel_rate * MAX_LINEAR_VELOCITY : 0.0;
                    angular_vel = abs(angular_vel_rate) >= JOY_DEAD_ZONE_PERCENTAGE ? angular_vel_rate * MAX_ANGULAR_VELOCITY : 0.0;

                    _drive.Drive(linear_vel, angular_vel);
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
    else{
    _drive.Stop();
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
