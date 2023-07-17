#include <Arduino.h>
#include <ros.h>

#include <Encoder.h>

#include "Naviton.h"

Naviton nvt;

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