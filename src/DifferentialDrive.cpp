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
void DifferentialDrive::Init(double footprint_width, double wheel_radius, double ppr, double dt, double max_power, double pid_params[])
{
    _footprint_width_2 = footprint_width * 0.5;
    _footprint_width_inv = 1.0 / footprint_width;
    _time_last = micros();
    _wheel_l.Init(wheel_radius, ppr, dt, max_power, pid_params);
    _wheel_r.Init(wheel_radius, ppr, dt, max_power, pid_params);
    Stop();
}

/// @brief Inverse Kinematics
void DifferentialDrive::Update()
{
    _wheel_l.Update();
    _wheel_r.Update();

    double velocity_l = _wheel_l.GetVelocity();
    double velocity_r = _wheel_r.GetVelocity();

    _linear_velocity = (- velocity_l + velocity_r) * 0.5;
    _angular_velocity = (velocity_l + velocity_r) * _footprint_width_inv;
}

/// @brief Forward Kinematics
/// @param linear_velocity [m/s]
/// @param angular_velocity [rad/s]
void DifferentialDrive::Drive(double linear_velocity, double angular_velocity)
{
    angular_velocity *= _footprint_width_2; // [rad/s] -> [m/s]
    _wheel_l.Drive(-linear_velocity + angular_velocity);
    _wheel_r.Drive(linear_velocity + angular_velocity);
}

/// @brief
void DifferentialDrive::Stop()
{
    _wheel_l.Stop();
    _wheel_r.Stop();
}

void DifferentialDrive::Accelerate(double linear_velocity, double angular_velocity, double max_linear_accelerate, double max_angular_accelerate)
{
    unsigned long time_now = micros();
    double _dt = (time_now - _time_last);
    _time_last = time_now;

    _linear_velocity += constrain((linear_velocity - _linear_velocity)*1e6/_dt, -max_linear_accelerate, max_linear_accelerate) * _dt / 1e6;
    _angular_velocity += constrain((angular_velocity - _angular_velocity)*1e6/_dt, -max_angular_accelerate, max_angular_accelerate) * _dt / 1e6;

    _linear_velocity = constrain(_linear_velocity, -1.0, 1.0);
    _angular_velocity = constrain(_angular_velocity, -1.0, 1.0);

    Drive(_linear_velocity, _angular_velocity);
}

void DifferentialDrive::DecelerateStop()
{
    Accelerate(0, 0, 2.0, 1.0);
}

/// @brief
/// @return _linear_velocity [m/s]
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

double DifferentialDrive::GetLeftWheelVelocity()
{
    return _wheel_l.GetVelocity();
}

double DifferentialDrive::GetRightWheelVelocity()
{
    return _wheel_r.GetVelocity();
}
