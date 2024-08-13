#ifndef HARDWARE_PARAMS_H
#define HARDWARE_PARAMS_H

#define I2C_SCL                 33
#define I2C_SDA                 34

#define PS3_WIRELESS_ADDRESS    0x73
#define PS3_WIRED_ADDRESS       0x74

#define BNO_ID                  -1
#define BNO_ADDRESS             0x28

#define EMERGENCY_STOP_PIN      26
#define AUTO_SWITCH_PIN         11
#define MANUAL_SWITCH_PIN       8

// ENCODER_ALPHA, ENCODER_BETA, MD_PWM, MD_DIR
#define LEFT_WHEEL_PINS         15,16,22,23
#define RIGHT_WHEEL_PINS        36,37,20,21

#define FOOTPRINT_WIDTH         0.53
#define WHEEL_DIAMETER          0.315

#define WHEEL_ENCODER_PPR       8192.0

#endif