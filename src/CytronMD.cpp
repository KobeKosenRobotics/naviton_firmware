#include "CytronMD.h"

CytronMD::CytronMD()
{

}

CytronMD::CytronMD(int pin_pwm, int pin_dir)
{
    Attach(pin_pwm, pin_dir);
}

void CytronMD::Attach(int pin_pwm, int pin_dir)
{
    _pin_pwm = pin_pwm;
    _pin_dir = pin_dir;

    analogWrite(_pin_pwm, 0);
    pinMode(_pin_dir, OUTPUT);
    digitalWrite(_pin_dir, LOW);
}

void CytronMD::Drive(double power)
{
    power = constrain(power, -1.0, 1.0);
    
    analogWrite(_pin_pwm, abs(power) * 255.0);
    digitalWrite(_pin_dir, power < 0 ? LOW : HIGH);
}

void CytronMD::WriteMicroseconds(int pulse)
{
    Drive(map(pulse, 1000, 2000, -1.0, 1.0));
}

void CytronMD::Stop()
{
    Drive(0.0);
}