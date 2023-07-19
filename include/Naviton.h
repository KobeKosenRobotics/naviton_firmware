/// @file   Naviton.h
/// @brief
/// @date   2023.07.18
/// @author Akiro Harada

#ifndef NAVITON_H
#define NAVITON_H

#include <Arduino.h>
#include <Wire.h>

#include "config/HardwareParams.h"
#include "config/SoftwareParams.h"

#include "PS3I2C.h"
#include "DifferentialDrive.h"

class Naviton
{
    protected:
        PS3I2C _ps3_wireless;
        PS3I2C _ps3_wired;
        DifferentialDrive _drive;

        bool _controller_mode = false; // false : wireless, true : wired
    public:
        Naviton();
        virtual void Init();
        virtual void Update();
        virtual void UpdateInput();
};

#endif