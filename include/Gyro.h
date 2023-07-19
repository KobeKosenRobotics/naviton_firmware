#ifndef GYRO_H
#define GYRO_H

#include <Adafruit_BNO055.h>

#ifndef DEG2RAD
#define DEG2RAD 0.0174533
#endif

#ifndef RAD2DEG
#define RAD2DEG 57.2958
#endif

class Gyro
{
    private:
        Adafruit_BNO055 _bno;

        double _roll, _pitch, _yaw; // [rad]

        void CalcRPY(double q0, double q1, double q2, double q3);
    public:
        Gyro();
        Gyro(const int id, const int address);
        bool Init();
        void Update();
        double GetRoll();   // [rad]
        double GetPitch();  // [rad]
        double GetYaw();    // [rad]
};

#endif