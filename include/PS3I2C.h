/// @file   PID.h
/// @brief  PID Controller with anti windup
/// @date   2023.07.19
/// @author Akiro Harada

#ifndef PS3_I2C_H
#define PS3_I2C_H

#include <Arduino.h>
#include <Wire.h>

#ifndef I2C_SCL
#define I2C_SCL 33
#endif

#ifndef I2C_SDA
#define I2C_SDA 34
#endif

enum PS3Axis
{
    LY,
    LX,
    RY,
    RX,
    L2,
    R2
};

enum PS3Button
{
    CIRCLE,
    TRIANGLE,
    SQUARE,
    CROSS,
    UP,
    RIGHT,
    DOWN,
    LEFT,
    L1,
    R1,
    L3,
    R3,
    START,
    SELECT,
    PS
};

class PS3I2C
{
    private:
        int _slave_address = 0x73;

        byte _data_raw[8];
        byte _data_last[8];
    public:
        PS3I2C();
        PS3I2C(const int slave_address);
        void Init();
        void Init(const int slave_address);

        void Update();

        byte GetAxis(PS3Axis axis);
        bool GetClick(PS3Button button);
        bool GetPress(PS3Button button);

        bool IsConnected();
};

#endif