#include "Pump.h"

Pump::Pump()
{

}

Pump::Pump(int pin_pwm, int pin_dir) : _md(pin_pwm, pin_dir)
{
}

void Pump::On()
{
    _md.Drive(_power);
}

void Pump::Off()
{
    _md.Stop();
}

void Pump::Drive(bool state)
{
    return state ? On() : Off();
}

void Pump::SetPower(double power)
{
    _power = constrain(power, -1.0, +1.0);
}