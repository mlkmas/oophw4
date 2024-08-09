#include "Keyboard.h"
#include <iostream>

Keyboard::Keyboard(int price, const std::string& manufacturer, const std::string& color, bool isWireless, int numOfKeys)
        : Item(price, manufacturer), // Initialize the Item base class
          PeripheralDevice(price, manufacturer, color, isWireless, DeviceType::Keyboard), // Initialize the PeripheralDevice base class
          numOfKeys(numOfKeys) {}
int Keyboard::getNumberOfKeys() const
{
    return numOfKeys;
}

void Keyboard::setNumberOfKeys(int nok)
{
    numOfKeys = nok;
}
Keyboard::Keyboard(const Keyboard &other) : PeripheralDevice(other), Item(other),numOfKeys(other.numOfKeys)
{}

Keyboard *Keyboard::clone() const
{
    return new Keyboard(*this);
}
void Keyboard::connect( Computer& computer)
{
    std::cout << "Connecting a keyboard" << std::endl;
    PeripheralDevice::connect(computer);
}

Keyboard::operator std::string() const
{
    return PeripheralDevice::operator std::string() + ", Keyboard with "+std::to_string(numOfKeys)+" keys";
}
void Keyboard::print() const
{
    PeripheralDevice::print();
    std::cout<< ", Keyboard with "+std::to_string(numOfKeys)+" keys"<<std::endl;
}