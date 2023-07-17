#ifndef WHEEL_H
#define WHEEL_H

#include <Encoder.h>

#include "CytronMD.h"
#include "PID.h"

class Wheel
{
    private:
        Encoder _encoder;
        CytronMD _motor;

        PID _pid;

        double _ppr_inv;

        double _velocity_now;       // [rad/s]
        double _velocity_target;    // [rad/s]

        double _pulse_last;
        unsigned long _time_last;   // [ms]
    public:
        Wheel();
        Wheel(int pin_alpha, int pin_beta, double ppr, int pin_pwm, int pin_dir);
        void Init();
        void Update();
        void Drive(double velocity);
        double GetVelocity();
};

#endif