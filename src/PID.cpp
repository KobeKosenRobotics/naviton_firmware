#include "PID.h"

PID::PID()
{

}

PID::PID(double k_p, double k_i, double k_d, double k_b, double n, double dt) 
{
    SetGains(k_p, k_i, k_d, k_b, n, dt);
}

void PID::Init()
{

}

void PID::Init(double k_p, double k_i, double k_d, double k_b, double n, double dt)
{
    SetGains(k_p, k_i, k_d, k_b, n, dt);
}

void PID::Update(double error)
{
    unsigned long time_now = micros();
    _dt_real += (time_now - _time_last);
    _time_last = time_now;
    if(_dt_real < _dt) return;
    _dt_real -= _dt;

    double p = _k_p * error;
    _i = _k_i * (error + _error_last);
    _d = _k_f * _d + _k_d * (error - _error_last);

    double u = p + _i + _d;
    double awVal = constrain(u, _output_min, _output_max) - u;
    _d += _k_b * (awVal + _awVal_last);

    _output = constrain(p + _i + _d, _output_min, _output_max);
    _error_last = error;
    _awVal_last = awVal;
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

void PID::SetGains(double k_p, double k_i, double k_d, double k_b, double n, double dt)
{
    _k_p = k_p;
    _k_i = 0.5 * k_i * dt;
    _k_d = (2 * k_d * n) / (2 + n * dt);
    _k_b = 0.5 * k_b * dt;
    _k_f = (2 - n * dt) / (2 + n * dt);

    _i = 0;
    _d = 0;
    
    _dt = dt * 1e6;
    _dt_real = 0;

    _error_last = 0;
    _time_last = micros();
}

void PID::SetSaturation(double output_min, double output_max)
{
    _output_min = output_min;
    _output_max = output_max;
}

