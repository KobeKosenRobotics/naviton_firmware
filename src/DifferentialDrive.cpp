#include "DifferentialDrive.h"

DifferentialDrive::DifferentialDrive()
{

}

DifferentialDrive::DifferentialDrive(double footprint_width, double wheel_radius, int pin_l[], int pin_r[], double ppr) : 
    _wheel_l(pin_l[0], pin_l[1], ppr, pin_l[2], pin_l[3]),
    _wheel_r(pin_r[0], pin_r[1], ppr, pin_r[2], pin_r[3])
{
    _footprint_width_2 = footprint_width * 0.001 * 0.5; // [mm] -> [m]
    _wheel_radius_inv = 1000.0 / wheel_radius;          // [mm] -> [1/m]
}

void DifferentialDrive::Init()
{
    _wheel_l.Init();
    _wheel_r.Init();
}

void DifferentialDrive::Update()
{
    _wheel_l.Update();
    _wheel_r.Update();

    // Inverse Kinematics
}

void DifferentialDrive::Drive(double linear_velocity, double angular_velocity)
{
    // Forward Kinematics
    double linear = linear_velocity * _wheel_radius_inv;
    double angular = angular_velocity * _footprint_width_2 * _wheel_radius_inv;
    double l_velocity = linear + angular;   // [rad/s]
    double r_velocity = linear - angular;   // [rad/s]

    _wheel_l.Drive(l_velocity);
    _wheel_r.Drive(r_velocity);
}