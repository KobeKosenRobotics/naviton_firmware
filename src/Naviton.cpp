#include "Naviton.h"

#define SELECT PS3Button::SELECT

Naviton::Naviton() :
    _ps3_wireless(PS3_WIRELESS_ADDRESS),
    _ps3_wired(PS3_WIRELD_ADDRESS),
    _drive(new int[4]{LEFT_WHEEL_PINS}, new int[4]{RIGHT_WHEEL_PINS})
{

}

void Naviton::Init()
{
    pinMode(EMERGENCY_STOP_PIN, INPUT_PULLUP);

    Serial.begin(SERIAL_BAUDRATE);

    _ps3_wireless.Init();
    _ps3_wired.Init();

    _drive.Init(FOOTPRINT_WIDTH, WHEEL_DIAMETER, WHEEL_ENCODER_PPR, WHEEL_LOOP_TIME, WHEEL_MAX_POWER, WHEEL_MAX_ACCELERATION, new double[5]{WHEEL_PID_GAIN, WHEEL_PID_AW_GAIN, WHEEL_PID_DERIATIVE_FILTER_COEF});
}

void Naviton::Update()
{
    _ps3_wireless.Update();
    _ps3_wired.Update();

    _drive.Update();

    Serial.println();
}

void Naviton::UpdateInput()
{
    if(_ps3_wireless.GetClick(SELECT)) _controller_mode = false;
    else if(_ps3_wired.GetClick(SELECT)) _controller_mode = true;

    if(digitalRead(EMERGENCY_STOP_PIN))
    {
        //_drive.Drive();
    }
    else
    {
        _drive.Stop();
    }
}