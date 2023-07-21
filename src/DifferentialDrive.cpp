#include "DifferentialDrive.h"

/// @brief Constructor
DifferentialDrive::DifferentialDrive()
{

}

/// @brief Constructor
/// @param pin_l 
/// @param pin_r 
DifferentialDrive::DifferentialDrive(int pin_l[], int pin_r[]) : 
    _wheel_l(pin_l[0], pin_l[1], pin_l[2], pin_l[3]),
    _wheel_r(pin_r[0], pin_r[1], pin_r[2], pin_r[3])
{
}

/// @brief Initialize
/// @param footprint_width 
/// @param wheel_radius 
/// @param ppr 
void DifferentialDrive::Init(double footprint_width, double wheel_radius, double ppr, double loopTime, double max_power, double max_acceleration, double pid_params[])
{
    _footprint_width_2 = footprint_width * 0.5;
    _wheel_l.Init(wheel_radius, ppr, loopTime, max_power, max_acceleration, pid_params);
    _wheel_r.Init(wheel_radius, ppr, loopTime, max_power, max_acceleration, pid_params);
}

/// @brief Inverse Kinematics
void DifferentialDrive::Update()
{
    _wheel_l.Update();
    _wheel_r.Update();

    double velocity_l = _wheel_l.GetVelocity();
    double velocity_r = _wheel_r.GetVelocity();
}

/// @brief Forward Kinematics
/// @param linear_velocity [m/s]
/// @param angular_velocity [rad/s]
void DifferentialDrive::Drive(double linear_velocity, double angular_velocity)
{
    angular_velocity *= _footprint_width_2; // [rad/s] -> [m/s]
    _wheel_l.Drive(linear_velocity - angular_velocity);
    _wheel_r.Drive(-linear_velocity - angular_velocity);
}

/// @brief 
void DifferentialDrive::Stop()
{
    _wheel_l.Stop();
    _wheel_r.Stop();
}

/// @brief 
/// @return _linear_veloicity [m/s]
double DifferentialDrive::GetLinearVelocity()
{
    return _linear_velocity;
}

/// @brief 
/// @return _angular_velocity [rad/s]
double DifferentialDrive::GetAngularVelocity()
{
    return _angular_velocity;
}