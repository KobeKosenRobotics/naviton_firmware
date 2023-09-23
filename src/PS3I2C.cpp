#include "PS3I2C.h"

/// @brief 
PS3I2C::PS3I2C()
{

}

/// @brief 
/// @param slave_address 
PS3I2C::PS3I2C(const int slave_address)
{
    Init(slave_address);
}

/// @brief 
void PS3I2C::Init()
{

}

/// @brief 
/// @param slave_address 
void PS3I2C::Init(const int slave_address)
{
    _slave_address = slave_address;
    Wire.begin();
}

/// @brief 
void PS3I2C::Update()
{
    Wire.requestFrom(_slave_address, 8);
    for(int i = 0; i < 8; i++)
    {
        _data_last[i] = _data_raw[i];
        _data_raw[i] = Wire.read();
    }
}

/// @brief 
/// @param axis 
/// @return 0~255
byte PS3I2C::GetAxis(PS3Axis axis)
{
    if(!IsConnected()) return 128;
    return _data_raw[static_cast<int>(axis)];
}

/// @brief 
/// @param button 
/// @return 
bool PS3I2C::GetClick(PS3Button button)
{
    if(!IsConnected()) return false;
    int id = static_cast<int>(button);
    return bitRead(_data_raw[id < 8 ? 6 : 7], id%8) && !bitRead(_data_last[id < 8 ? 6 : 7], id%8);
}

/// @brief 
/// @param button 
/// @return 
bool PS3I2C::GetPress(PS3Button button)
{
    if(!IsConnected()) return false;
    int id = static_cast<int>(button);
    return bitRead(_data_raw[id < 8 ? 6 : 7], id%8);
}

/// @brief 
/// @return 
bool PS3I2C::IsConnected()
{
    return bitRead(_data_raw[7], 7);
}