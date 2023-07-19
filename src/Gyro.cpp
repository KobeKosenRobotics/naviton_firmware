#include "Gyro.h"

/// @brief 
Gyro::Gyro()
{

}

/// @brief 
/// @param id 
/// @param address 
Gyro::Gyro(const int id, const int address) : _bno(id, address)
{

}

/// @brief 
/// @return 
bool Gyro::Init()
{
    if(!_bno.begin()) return false;
    _bno.setExtCrystalUse(true);
}

/// @brief 
void Gyro::Update()
{
    imu::Quaternion quat = _bno.getQuat();
    CalcRPY(quat.w(), quat.x(), quat.y(), quat.z());
}

/// @brief 
/// @param q0 
/// @param q1 
/// @param q2 
/// @param q3 
void Gyro::CalcRPY(double q0, double q1, double q2, double q3)
{
    double q0q0 = q0 * q0;
    double q0q1 = q0 * q1;
    double q0q2 = q0 * q2;
    double q0q3 = q0 * q3;
    double q1q1 = q1 * q1;
    double q1q2 = q1 * q2;
    double q1q3 = q1 * q3;
    double q2q2 = q2 * q2;
    double q2q3 = q2 * q3;
    double q3q3 = q3 * q3;
    _roll = atan2(2.0 * (q2q3 + q0q1), q0q0 - q1q1 - q2q2 + q3q3);
    _pitch = asin(2.0 * (q0q2 - q1q3));
    _yaw = atan2(2.0 * (q1q2 + q0q3), q0q0 + q1q1 - q2q2 - q3q3);
}

/// @brief 
/// @return [rad]
double Gyro::GetRoll()
{
    return _roll;
}

/// @brief 
/// @return [rad]
double Gyro::GetPitch()
{
    return _pitch;
}

/// @brief 
/// @return [rad]
double Gyro::GetYaw()
{
    return _yaw;
}