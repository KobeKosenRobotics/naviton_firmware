#ifndef NAVITON_H
#define NAVITON_H

#include <Arduino.h>
#include <Wire.h>

#include "config/HardwareParams.h"
#include "config/SoftwareParams.h"

#include "DifferentialDrive.h"

class Naviton
{
    private:
        DifferentialDrive _drive;
    public:
        Naviton();
        void Init();
        void Update();
};

#endif