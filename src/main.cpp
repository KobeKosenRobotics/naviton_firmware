#include <Arduino.h>
#include <ros.h>

#include "PS3I2C.h"
#include "NavitonROS.h"

ros::NodeHandle nh;

NavitonROS nvt;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    Wire.setSCL(I2C_SCL);
    Wire.setSDA(I2C_SDA);

    nh.initNode();

    nvt.Init(nh);
}

void loop()
{
    nvt.Update();

    nh.spinOnce();
}