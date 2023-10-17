#include "CytronMD.h"

/// @brief 
CytronMD::CytronMD()
{

}

/// @brief 
/// @param pin_pwm 
/// @param pin_dir 
CytronMD::CytronMD(int pin_pwm, int pin_dir)
{
    Attach(pin_pwm, pin_dir);
}

/// @brief 
/// @param pin_pwm 
/// @param pin_dir 
void CytronMD::Attach(int pin_pwm, int pin_dir)
{
    _pin_pwm = pin_pwm;
    _pin_dir = pin_dir;

    analogWriteFrequency(_pin_pwm, 20000);
    analogWrite(_pin_pwm, 0);
    pinMode(_pin_dir, OUTPUT);

    digitalWrite(_pin_dir, LOW);
}

/// @brief 
/// @param power -1.0~1.0
void CytronMD::Drive(double power)
{
    power = constrain(power, -1.0, 1.0);
    
    analogWrite(_pin_pwm, abs(power) * 255.0);
    digitalWrite(_pin_dir, power < 0 ? LOW : HIGH);
}

/// @brief 
/// @param pulse 1000~2000
void CytronMD::WriteMicroseconds(int pulse)
{
    Drive(map(pulse, 1000, 2000, -1.0, 1.0));
}

/// @brief 
void CytronMD::Stop()
{
    Drive(0.0);
}