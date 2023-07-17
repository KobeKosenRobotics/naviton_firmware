/// @file   PID.h
/// @brief  PID Controller with anti windup
/// @date   2023.07.18
/// @author Akiro Harada

#ifndef PID_H
#define PID_H

#include <Arduino.h>

class PID
{
    private:
        double _kp, _ki, _kd, _kb, _kf;
        unsigned long _time_last;

        double _i;
        double _d;

        double _error_last;
        double _awVal_last;

        double _output;
        double _output_min = -1e6;
        double _output_max = +1e6;
    public:
        PID();
        PID(double kp, double ki, double kd);
        void Init();
        void Update(double error);
        void ResetI();
        double GetOutput();
        void SetSaturation(double output_min, double output_max);
};

#endif