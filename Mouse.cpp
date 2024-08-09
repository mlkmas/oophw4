#include "Mouse.h"
#include <iostream>
Mouse::Mouse(int price, const std::string& manufacturer, const std::string& color, bool isWireless, int dpi)
        : Item(price, manufacturer), // Initialize the Item base class
          PeripheralDevice(price, manufacturer, color, isWireless, DeviceType::Mouse), // Initialize the PeripheralDevice base class
          dpi(dpi) {}
int Mouse::getDpi() const
{
    return dpi;
}
Mouse::Mouse(const Mouse &other) : Item(other), PeripheralDevice(other),dpi(other.dpi)
{}

Mouse *Mouse::clone() const
{
    return new Mouse(*this);
}
void Mouse::setDpi(int dpi)
{
    this->dpi = dpi;
}

void Mouse::connect( Computer& computer)
{
    std::cout << "Connecting a mouse" << std::endl;
    PeripheralDevice::connect(computer);
}

Mouse::operator std::string() const
{
    return PeripheralDevice::operator std::string() + ", Mouse with dpi : " + std::to_string(dpi);

}
void Mouse::print() const
{
    PeripheralDevice::print();
    std::cout<< ", Mouse with dpi : " + std::to_string(dpi)<<std::endl;

}