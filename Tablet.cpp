#include "Tablet.h"
#include <iostream>
Tablet::Tablet(int price, const std::string& manufacturer, const std::string& color,const std::string& cpu,bool isWireless,int screen):
Computer(price, manufacturer, cpu, false, 1)
,PeripheralDevice(price, manufacturer, color, isWireless, DeviceType::Tablet),screenSize(screen)
,Item(price,manufacturer){}


void Tablet::connect(Computer& computer)
{

    std::cout << "Connecting a Tablet" << std::endl;
    if( computerCount<ONE_COMPUTER)
        PeripheralDevice::connect(computer);

    else throw ConnectError();
}
Tablet::Tablet(const Tablet &other): Computer(other), PeripheralDevice(other), Item(other),screenSize(other.screenSize)
{}

Tablet *Tablet::clone() const
{
    return new Tablet(*this);
}
void Tablet::disconnect()
{
    std::cout << "the tablet is disconnecting" << std::endl;
    PeripheralDevice::disconnect();

}
Tablet::operator std::string() const
{
    // Combine the string representations from both base classes
    return Item::operator std::string()+", "+color+", CPU, Tablet with screen size: " + std::to_string(screenSize);
}
void Tablet::print() const
{
    //Tblet print
    PeripheralDevice::print();
}