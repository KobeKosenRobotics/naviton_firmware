#include <Arduino.h>

#include "NavitonROS.h"

NavitonROS nvt;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    nvt.Init();
}

void loop()
{
    nvt.Update();
}