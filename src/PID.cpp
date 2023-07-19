#include "PID.h"

PID::PID()
{

}

PID::PID(double k_p, double k_i, double k_d, double k_b, double n, double t) 
{
    SetGains(k_p, k_i, k_d, k_b, n, t);
}

void PID::Init()
{

}

void PID::Init(double k_p, double k_i, double k_d, double k_b, double n, double t)
{
    SetGains(k_p, k_i, k_d, k_b, n, t);
}

void PID::Update(double error)
{
    unsigned long time_now = millis();
    double dt = (time_now - _time_last) * 0.001;
    if(dt < _t) return;

    double p = _k_p * error;
    _i = _k_i * (error + _error_last);
    _d = _k_f * _d + _k_d * (error - _error_last);

    double u = p + _i + _d;
    double awVal = constrain(u, _output_min, _output_max) - u;
    _d += _k_b * (awVal + _awVal_last);

    _output = constrain(p + _i + _d, _output_min, _output_max);
    _error_last = error;
    _awVal_last = awVal;
    _time_last = time_now;
}

void PID::ResetI()
{
    _i = 0;
    _awVal_last = 0;
}

double PID::GetOutput()
{
    return _output;
}

void PID::SetGains(double k_p, double k_i, double k_d, double k_b, double n, double t)
{
    _t = t;

    _k_p = k_p;
    _k_i = 0.5 * k_i * _t;
    _k_d = (2 * k_d * n) / (2 + n * _t);
    _k_b = 0.5 * k_b * _t;
    _k_f = (2 - n * _t) / (2 + n * _t);

    _i = 0;
    _d = 0;
    _error_last = 0;
    _time_last = millis();
}

void PID::SetSaturation(double output_min, double output_max)
{
    _output_min = output_min;
    _output_max = output_max;
}

