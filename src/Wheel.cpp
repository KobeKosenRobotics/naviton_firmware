#include "Wheel.h"

Wheel::Wheel() : _encoder(0, 0)
{

}

Wheel::Wheel(int pin_alpha, int pin_beta, int pin_pwm, int pin_dir) : 
    _encoder(pin_alpha, pin_beta),
    _motor(pin_pwm, pin_dir)
{
}

void Wheel::Init(double radius, double ppr, double pid_params[])
{
    _radius = radius;
    _ppr_inv = 1.0 / ppr;

    _pid.Init(pid_params[0], pid_params[1], pid_params[2], pid_params[3], pid_params[4], pid_params[5]);
}

void Wheel::Update()
{
    unsigned long time_now = millis();
    double dt = (time_now - _time_last) * 0.001;
    long long pulse = _encoder.read();

    _velocity_now = (pulse - _pulse_last) * M_PI * _ppr_inv / dt;

    double velocity_diff = _velocity_now - _velocity_target;
    _pid.Update(velocity_diff);

    double power = _pid.GetOutput();
    _motor.Drive(power);

    _time_last = time_now;
    _pulse_last = pulse;
}

void Wheel::Drive(double velocity)
{
    Serial.println(velocity);
    _velocity_target = velocity;
}

double Wheel::GetVelocity()
{
    return _velocity_now;
}