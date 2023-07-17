#include "Naviton.h"

Naviton::Naviton() :
    _drive(FOOTPRINT_WIDTH, WHEEL_RADIUS, new int[4]{LEFT_WHEEL_PINS}, new int[4]{RIGHT_WHEEL_PINS}, WHEEL_ENCODER_PPR)
{

}

void Naviton::Init()
{
    Serial.begin(SERIAL_BAUDRATE);

    Wire.begin();
    Wire.setSCL(I2C_SCL);
    Wire.setSDA(I2C_SDA);
}

void Naviton::Update()
{
    _drive.Update();
    Serial.println();
}