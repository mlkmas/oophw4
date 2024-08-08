#include "Tablet.h"
#include <iostream>
Tablet::Tablet(int price, const std::string& manufacturer, const std::string& color,const std::string& cpu,bool isWireless,int screen):
Computer(price, manufacturer, cpu, false, 1)
,PeripheralDevice(price, manufacturer, color, isWireless, DeviceType::Tablet),screenSize(screen)
,Item(price,manufacturer){}


void Tablet::connect(Computer& computer)
{

    std::cout << "Connecting a Tablet" << std::endl;
    if( computerCount<1)
        PeripheralDevice::connect(computer);

    else throw ConnectError();
}
void Tablet::disconnect()
{
    std::cout << "the tablet is disconnecting" << std::endl;
    PeripheralDevice::disconnect();

}
Tablet::operator std::string() const
{
    // Combine the string representations from both base classes
    return PeripheralDevice::operator std::string() + ", " + Computer::operator std::string() + ", Screen size: " + std::to_string(screenSize) + " inches";
}
void Tablet::print() const
{
    //Tblet print
    PeripheralDevice::print();
}