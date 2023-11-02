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
void Wheel::Init(double diameter, double ppr, double dt, double max_power, double pid_params[])
{
    _diameter = diameter;
    _ppr_inv = 1.0 / ppr;
    _power_max = max_power;

    _dt = dt * 1e6;
    _dt_real = 0;

    _time_last = micros();

    _dt_inv = 1.0 / dt;

    _pid.Init(pid_params[0], pid_params[1], pid_params[2], pid_params[3], pid_params[4], dt);
    Stop();
}

/// @brief 
void Wheel::Update()
{
    unsigned long time_now = micros();
    _dt_real += (time_now - _time_last);
    _time_last = time_now;
    if(_dt_real < _dt) return;
    _dt_real -= _dt;

    long long pulse_now = _encoder.read();

    _velocity_now = (pulse_now - _pulse_last) * M_PI * _ppr_inv * _diameter * _dt_inv;
    _acceleration = (_velocity_now - _velocity_last) * _dt_inv;

    double velocity_diff = _velocity_target - _velocity_now;
    _pid.Update(velocity_diff);
    double output_now = _pid.GetOutput();
    _power += (output_now - _output_last);

    double power_max = min(_power_max, abs(_velocity_target) * VELOCITY_TO_POWER_COEF);
    _power = constrain(_power, -power_max, power_max);
    _motor.Drive(_power);

    _pulse_last = pulse_now;
    _velocity_last = _velocity_now;
    _output_last = output_now;
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