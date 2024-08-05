#include "PeripheralDevice.h"
#include <iostream>
PeripheralDevice::PeripheralDevice(int price, const std::string& manufacturer, const std::string& color, bool isWireless):
        Item(price,manufacturer),color(color),isWireless(isWireless){}

std::string PeripheralDevice::getColor() const
{
    return color;
}

bool PeripheralDevice::getIsWireless() const
{
    return isWireless;
}

void PeripheralDevice::setColor(const std::string& color)
{
    this->color = color;
}

void PeripheralDevice::setIsWireless(bool isWireless)
{
    this->isWireless = isWireless;
}

void PeripheralDevice::connect(const Computer& computer)
{
    std::cout << static_cast<std::string>(*this) + " is connecting to computer: " + static_cast<std::string>(computer) << std::endl;
}

PeripheralDevice::operator std::string() const
{
    return Item::operator std::string()+", "+(isWireless?"Wireless":"Wired")+", "+color;
}
