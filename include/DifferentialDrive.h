#ifndef DIFFERENTIAL_DRIVE_H
#define DIFFERENTIAL_DRIVE_H

#include "Wheel.h"

class DifferentialDrive
{
    private:
        Wheel _wheel_l;
        Wheel _wheel_r;

        double _footprint_width_2;      // [m]
        double _wheel_radius_inv;       // [1/m]
    public:
        DifferentialDrive();
        DifferentialDrive(double footprint_width, double wheel_radius, int pin_l[], int pin_r[], double ppr);
        void Init();
        void Update();
        void Drive(double linear_velocity, double angular_velocity);    // [m/s], [rad/s]
};

#endif