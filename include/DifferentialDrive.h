/// @file   DifferentialDrive.h
/// @brief
/// @date   2023.07.18
/// @author Akiro Harada

#ifndef DIFFERENTIAL_DRIVE_H
#define DIFFERENTIAL_DRIVE_H

#include "Wheel.h"

class DifferentialDrive {
private:
  Wheel _wheel_l;
  Wheel _wheel_r;

  double _linear_velocity, _angular_velocity;

  double _footprint_width_2;
  double _footprint_width_inv; // [m]

  unsigned long _time_last;
public:
  DifferentialDrive();
  DifferentialDrive(int pin_l[], int pin_r[]);

  void Init(double footprint_width, double wheel_radius, double ppr, double dt,
            double max_power, double pid_params[]); // [m], [m], [], []
  void Update();
  void Drive(double linear_velocity, double angular_velocity); // [m/s], [rad/s]
  void Stop();
  void Accelerate(double linear_velocity, double angular_velocity, double max_linear_accelerate, double max_angular_accelerate);
  void DecelerateStop();

  double GetLinearVelocity();
  double GetAngularVelocity();

  double GetLeftWheelVelocity();
  double GetRightWheelVelocity();
};

#endif