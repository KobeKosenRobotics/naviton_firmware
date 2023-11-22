#ifndef UVG_ROS_H
#define UVG_ROS_H

#include <ros.h>
#include <std_msgs/Bool.h>

#include "config/HardwareParams.h"
#include "config/RosParams.h"

#include "Pump.h"

#ifndef PUMP_CMD_TOPIC
#define PUMP_CMD_TOPIC "/naviton/uvg_controller/pump_cmd"
#endif

#ifndef PUMP_PWM_PIN
#define PUMP_PWM_PIN 10
#endif

#ifndef PUMP_DIR_PIN
#define PUMP_DIR_PIN 9
#endif

class UvgROS
{
    private:
        Pump _pump;

        ros::Subscriber<std_msgs::Bool, UvgROS> _pump_cmd_sub;
        std_msgs::Bool _pump_cmd;

        unsigned long _last_subscribed_time;
    public:
        UvgROS();
        void Init(ros::NodeHandle& nh);
        void Update();
        void pump_cmd_cb(const std_msgs::Bool& pump_cmd);
};

#endif