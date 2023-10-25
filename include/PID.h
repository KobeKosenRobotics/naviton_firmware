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
        double _k_p, _k_i, _k_d, _k_b, _k_f;

        unsigned long _dt;
        unsigned long _dt_real;
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
        PID(double k_p, double k_i, double k_d, double k_b, double n, double dt);
        void Init();
        void Init(double k_p, double k_i, double k_d, double k_b, double n, double dt);
        void Update(double error);
        void ResetI();
        double GetOutput();
        void SetGains(double k_p, double k_i, double k_d, double k_b, double n, double dt);
        void SetSaturation(double output_min, double output_max);
};

#endif