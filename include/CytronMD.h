#ifndef CYTRON_MD_H
#define CYTRON_MD_H

#include <Arduino.h>

class CytronMD
{
    private:
        int _pin_pwm, _pin_dir;
    public:
        CytronMD();
        CytronMD(int pin_pwm, int pin_dir);
        void Attach(int pin_pwm, int pin_dir);
        void Drive(double speed);
        void WriteMicroseconds(int pulse);
        void Stop();
};

#endif