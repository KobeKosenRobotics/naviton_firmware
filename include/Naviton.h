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

#include "DifferentialDrive.h"

class Naviton
{
    protected:
        DifferentialDrive _drive;
    public:
        Naviton();
        virtual void Init();
        virtual void Update();
};

#endif