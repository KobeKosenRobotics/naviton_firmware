#ifndef SOFTWARE_PARAMS_H
#define SOFTWARE_PARAMS_H

#define SERIAL_BAUDRATE                     57600

#define WHEEL_LOOP_TIME                     0.05

#define WHEEL_MAX_POWER                     1.0

#define WHEEL_PID_GAIN                      0.01,0.0,0.0
#define WHEEL_PID_AW_GAIN                   1.0
#define WHEEL_PID_DERIVATIVE_FILTER_COEF     0.01

#define MANUAL_MAX_LINEAR_VEL               1.0
#define MANUAL_MAX_ANGULAR_VEL              1.0
#define MANUAL_MINIMUM_LINEAR_VEL             0.1
#define MANUAL_MINIMUM_ANGULAR_VEL            0.1

#endif