#include "PID.h"

PID::PID()
{

}

PID::PID(double kp, double ki, double kd) : 
    _kp(kp),
    _ki(ki),
    _kd(kd)
{
}

void PID::Init()
{

}

void PID::Update(double error)
{
    unsigned long time_now = millis();
    double dt = (time_now - _time_last) * 0.001;

    double p = _kp * error;
    _i = _ki * (error + _error_last) * dt;
    _d = _kf * _d + _kd * (error - _error_last) / dt;

    double awVal = constrain(_output, _output_min, _output_max);
    _d += _kb * (awVal + _awVal_last);

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

void PID::SetSaturation(double output_min, double output_max)
{
    _output_min = output_min;
    _output_max = output_max;
}

