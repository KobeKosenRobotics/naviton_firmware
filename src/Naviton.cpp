#include "Naviton.h"

Naviton::Naviton() :
    _drive(new int[4]{LEFT_WHEEL_PINS}, new int[4]{RIGHT_WHEEL_PINS})
{

}

void Naviton::Init()
{
    Serial.begin(SERIAL_BAUDRATE);

    Wire.begin();
    Wire.setSCL(I2C_SCL);
    Wire.setSDA(I2C_SDA);

    _drive.Init(FOOTPRINT_WIDTH, WHEEL_RADIUS, WHEEL_ENCODER_PPR, new double[6]{WHEEL_PID_GAIN, WHEEL_PID_AW_GAIN, WHEEL_PID_DERIATIVE_FILTER_COEF, WHEEL_PID_LOOP_TIME});
}

void Naviton::Update()
{
    _drive.Update();
    Serial.println();
}