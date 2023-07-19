#include <Arduino.h>
#include <ros.h>

#include "PS3I2C.h"
#include "NavitonROS.h"

ros::NodeHandle nh;

PS3I2C ps3_wireless(0x73);
PS3I2C ps3_wired(0x74);
NavitonROS nvt;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    nh.initNode();

    ps3_wireless.Init();
    ps3_wired.Init();

    nvt.Init(nh);
}

void loop()
{
    ps3_wireless.Update();
    ps3_wired.Update();

    nvt.Update();
    
    nh.spinOnce();
}