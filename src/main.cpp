#include <Arduino.h>
#include <ros.h>

#include "PS3I2C.h"
#include "NavitonROS.h"

ros::NodeHandle nh;

NavitonROS nvt;

void setup()
{
    nh.initNode();

    nvt.Init(nh);
}

void loop()
{
    nvt.Update();
    nvt.UpdateInput();

    nh.spinOnce();
}