#ifndef ODOMETER_H
#define ODOMETER_H

#include <Arduino.h>

class Odometer
{
    private:
        double _x;
        double _y;
        double _z;
        unsigned long _time_last;
    public:
        void Init();
        void Update(double linear_velocity, double gyro_yaw, double gyro_pitch);
        double GetX();
        double GetY();
        double GetZ();
};

#endif