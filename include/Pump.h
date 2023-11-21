#ifndef PUMP_H
#define PUMP_H

#include <Arduino.h>
#include "CytronMD.h"

class Pump
{
    private:
        CytronMD _md;
        int _dir;
        double _power = 1.0;
    public:
        Pump();
        Pump(int pin_pwm, int pin_dir, bool direction);
        void On();
        void Off();
        void Drive(bool state);
        void SetPower(double power);
};

#endif