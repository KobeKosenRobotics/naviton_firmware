#include <Arduino.h>
#include <ros.h>

#include "NavitonROS.h"

ros::NodeHandle nh;

NavitonROS nvt;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    nh.initNode();
    nvt.Init(nh);
}

void loop()
{
    nvt.Update();
    nh.spinOnce();
}