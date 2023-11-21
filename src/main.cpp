#include <Arduino.h>
#include <ros.h>

#include "NavitonROS.h"
#include "UvgROS.h"

ros::NodeHandle nh;

NavitonROS nvt;
UvgROS uvg;

void setup()
{
    nh.initNode();

    nvt.Init(nh);
    uvg.Init(nh);
}

void loop()
{
    nvt.Update();
    nvt.UpdateInput();

    uvg.Update();

    nh.spinOnce();
}