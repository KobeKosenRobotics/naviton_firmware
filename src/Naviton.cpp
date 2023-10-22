#include "Naviton.h"

#define SELECT PS3Button::SELECT

Naviton::Naviton() :
    _ps3_wireless(PS3_WIRELESS_ADDRESS),
    _ps3_wired(PS3_WIRED_ADDRESS),
    _drive(new int[4]{LEFT_WHEEL_PINS}, new int[4]{RIGHT_WHEEL_PINS}),
    _gyro(BNO_ID, BNO_ADDRESS)
{

}

void Naviton::Init()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    pinMode(EMERGENCY_STOP_PIN, INPUT_PULLUP);

    Serial.begin(SERIAL_BAUDRATE);
    Wire.setSCL(I2C_SCL);
    Wire.setSDA(I2C_SDA);

    _ps3_wireless.Init();
    _ps3_wired.Init();

    _drive.Init(FOOTPRINT_WIDTH, WHEEL_DIAMETER, WHEEL_ENCODER_PPR, WHEEL_LOOP_TIME, WHEEL_MAX_POWER, WHEEL_MAX_ACCELERATION, new double[5]{WHEEL_PID_GAIN, WHEEL_PID_AW_GAIN, WHEEL_PID_DERIVATIVE_FILTER_COEF});
    _drive.Stop();

    _gyro.Init();

    _odom.Init();

    _ps3_used = nullptr;
}

void Naviton::Update()
{
    _ps3_wireless.Update();
    _ps3_wired.Update();

    _drive.Update();

    _gyro.Update();

    _odom.Update(_drive.GetLinearVelocity(), _gyro.GetYaw(), _gyro.GetPitch());

    Serial.println(_drive.GetLeftWheelVelocity());
}

void Naviton::UpdateInput()
{
    if(_ps3_wireless.GetClick(SELECT)) _ps3_used = &_ps3_wireless;
    else if(_ps3_wired.GetClick(SELECT)) _ps3_used = &_ps3_wired;

    if(!_ps3_used->IsConnected()) _ps3_used = nullptr;

    if(digitalRead(EMERGENCY_STOP_PIN) && _ps3_used != nullptr)
    {
        double linear_vel = 0.0;
        double angular_vel = 0.0;
        double linear_vel_orig = map((double)_ps3_used->GetAxis(PS3Axis::LY), 255, 0, -MANUAL_MAX_LINEAR_VEL, MANUAL_MAX_LINEAR_VEL);
        double angular_vel_orig = map((double)_ps3_used->GetAxis(PS3Axis::RX), 255, 0, -MANUAL_MAX_ANGULAR_VEL, MANUAL_MAX_ANGULAR_VEL);

        (double)_ps3_used->GetAxis(PS3Axis::LY) >= MANUAL_MINIMUM_LINEAR_VEL ? linear_vel = linear_vel_orig : linear_vel = 0.0;
        (double)_ps3_used->GetAxis(PS3Axis::LY) >= MANUAL_MINIMUM_ANGULAR_VEL ? angular_vel = angular_vel_orig : angular_vel = 0.0;

        _drive.Drive(linear_vel, angular_vel);
    }
    else
    {
        _drive.Stop();
    }
}