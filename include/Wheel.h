/// @file   Wheel.h
/// @brief
/// @date   2023.07.18
/// @author Akiro Harada

#ifndef WHEEL_H
#define WHEEL_H

#ifndef VELOCITY_TO_POWER_COEF
#define VELOCITY_TO_POWER_COEF 1.0
#endif

#include <Encoder.h>

#include "CytronMD.h"
#include "PID.h"

class Wheel
{
    private:
        Encoder _encoder;
        CytronMD _motor;

        PID _pid;

        double _diameter;
        double _ppr_inv;
        double _power_max;

        unsigned long _dt;
        unsigned long _dt_real;

        double _velocity_now;       // [m/s]
        double _velocity_target;    // [m/s]
        double _acceleration;       // [m/s^2]

        double _power;

        double _pulse_last;
        unsigned long _time_last;   // [micros]
        double _velocity_last;
        double _output_last;

        double _dt_inv;
    public:
        Wheel();
        Wheel(int pin_alpha, int pin_beta, int pin_pwm, int pin_dir);

        void Init(double diameter, double ppr, double dt, double max_power, double pid_params[]);
        void Update();
        void Drive(double velocity);
        void Stop();

        double GetVelocity();
        double GetAcceleration();
        double GetOutput();
};

#endif