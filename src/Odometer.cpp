#include "Odometer.h"

void Odometer::Init()
{
    _x = _y = _z = 0.0;
    _time_last = micros();
}

void Odometer::Update(double linear_velocity, double yaw, double pitch)
{
    unsigned long time_now = micros();

    double diff = linear_velocity * (time_now - _time_last) * 0.000001;
    double diff_c = diff * cos(pitch);

    _x += diff_c * cos(yaw);
    _y += diff_c * sin(yaw);
    _z += diff * sin(pitch);

    _time_last = time_now;
}

double Odometer::GetX()
{
    return _x;
}

double Odometer::GetY()
{
    return _y;
}

double Odometer::GetZ()
{
    return _z;
}