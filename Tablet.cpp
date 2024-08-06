#include "Tablet.h"
#include <iostream>
Tablet::Tablet(int price, const std::string& manufacturer, const std::string& color,const std::string& cpu,
       bool isWireless,int screen) :PeripheralDevice(price, manufacturer, color, isWireless, DeviceType::Tablet),screenSize(screen) {}


void Tablet::connect(Computer& computer)
{
    std::cout << "Connecting a Tablet" << std::endl;
    if(this->getCompCounter()<1)
       PeripheralDevice::connect(computer);
    //else its already connected to a computer
}
