#include "UvgROS.h"

UvgROS::UvgROS() : _pump(PUMP_PWM_PIN, PUMP_DIR_PIN), _pump_cmd_sub(PUMP_CMD_TOPIC, &UvgROS::pump_cmd_cb, this)
{

}

void UvgROS::Init(ros::NodeHandle& nh)
{
    nh.subscribe(_pump_cmd_sub);
}

void UvgROS::Update()
{
    if(millis() - _last_subscribed_time > 1000)
    {
        _pump.Off();
        return;
    }

    _pump.Drive(_pump_cmd.data);
}

void UvgROS::pump_cmd_cb(const std_msgs::Bool& pump_cmd)
{
    _pump_cmd = pump_cmd;
    _last_subscribed_time = millis();
}