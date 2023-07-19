/// @file   DifferentialDrive.h
/// @brief
/// @date   2023.07.18
/// @author Akiro Harada

#ifndef DIFFERENTIAL_DRIVE_H
#define DIFFERENTIAL_DRIVE_H

#include "Wheel.h"

class DifferentialDrive
{
    private:
        Wheel _wheel_l;
        Wheel _wheel_r;

        double _linear_velocity, _angular_velocity;

        double _footprint_width_2;                                          // [m]
    public:
        DifferentialDrive();
        DifferentialDrive(int pin_l[], int pin_r[]);
        void Init(double footprint_width, double wheel_radius, double ppr); // [m], [m], []
        void Update();
        void Drive(double linear_velocity, double angular_velocity);        // [m/s], [rad/s]

        double GetLinearVelocity();
        double GetAngularVelocity();
};

#endif