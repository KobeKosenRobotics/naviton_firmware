#include "Wheel.h"

/// @brief 
Wheel::Wheel() : _encoder(0, 0)
{

}

/// @brief 
/// @param pin_alpha 
/// @param pin_beta 
/// @param pin_pwm 
/// @param pin_dir 
Wheel::Wheel(int pin_alpha, int pin_beta, int pin_pwm, int pin_dir) : 
    _encoder(pin_alpha, pin_beta),
    _motor(pin_pwm, pin_dir)
{
}

/// @brief 
/// @param radius 
/// @param ppr 
/// @param loopTime
/// @param max_power
/// @param max_acceleration
/// @param pid_params
void Wheel::Init(double diameter, double ppr, double loopTime, double max_power, double max_acceleration, double pid_params[])
{
    _diameter = diameter;
    _ppr_inv = 1.0 / ppr;
    _loopTime = loopTime;
    _power_max = max_power;

    _pid.Init(pid_params[0], pid_params[1], pid_params[2], pid_params[3], pid_params[4], loopTime);
    _pid.SetSaturation(-max_acceleration, max_acceleration);
}

/// @brief 
void Wheel::Update()
{
    unsigned long time_now = micros();
    double dt = (time_now - _time_last) * 1e-6; // [mis]
    if(dt < _loopTime) return;
    long long pulse = _encoder.read();

    _velocity_now = (pulse - _pulse_last) * M_PI * _ppr_inv * _diameter / dt;
    _acceleration = (_velocity_now - _velocity_old) / dt;

    double velocity_diff = _velocity_now - _velocity_target;
    _pid.Update(velocity_diff);

    _power += _pid.GetOutput() * dt;
    _power = constrain(_power, -_power_max, _power_max);
    _motor.Drive(_power);

    _time_last = time_now;
    _pulse_last = pulse;
    _velocity_old = _velocity_now;
}

/// @brief 
/// @param velocity [m/s]
void Wheel::Drive(double velocity)
{
    _velocity_target = velocity;
}

/// @brief 
void Wheel::Stop()
{
    _pid.ResetI();
    _motor.Stop();
    _power = 0;
    _velocity_target = 0;
}

/// @brief 
/// @return [m/s]
double Wheel::GetVelocity()
{
    return _velocity_now;
}

/// @brief 
/// @return [m/s^2]
double Wheel::GetAcceleration()
{
    return _acceleration;
}

/// @brief 
/// @return 
double Wheel::GetOutput()
{
    return _power;
}