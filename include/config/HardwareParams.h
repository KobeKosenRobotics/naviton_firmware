#ifndef HARDWARE_PARAMS_H
#define HARDWARE_PARAMS_H

#define I2C_SCL 33
#define I2C_SDA 34

#define PS3_WIRELESS_ADDRESS    0x73
#define PS3_WIRELD_ADDRESS      0x74

#define BNO_ID                  -1
#define BNO_ADDRESS             0x29

#define EMERGENCY_STOP_PIN      22
#define AUTO_MANUAL_SWITCH_PIN  30

// ENCODER_ALPHA, ENCODER_BETA, MD_PWM, MD_DIR
#define LEFT_WHEEL_PINS     1,2,3,4
#define RIGHT_WHEEL_PINS    1,2,3,4

#define FOOTPRINT_WIDTH 55.0
#define WHEEL_RADIUS 157.5

#define WHEEL_ENCODER_PPR 8192.0

#endif