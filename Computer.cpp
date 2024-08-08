#include <iostream>
#include "Computer.h"
#include "PeripheralDevice.h"
Computer::Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop,const int numOfPorts):
        Item(price,manufacturer),cpu(cpu),isALaptop(isALaptop),numOfPorts(numOfPorts),devicesCounter(0){}
void Computer::setCpu(const std::string& cpu)
{
    this->cpu = cpu;
}
void Computer::setIsALaptop(bool isALaptop)
{
    this->isALaptop = isALaptop;
}
std::string Computer::getCpu() const
{
    return cpu;
}
bool Computer::getIsALaptop() const
{
    return isALaptop;
}
Computer::operator std::string() const
{
    return Item::operator std::string() + "," + (isALaptop ? "Laptop" : "Desktop") + ", " + cpu;
}
void Computer::print() const
{
    Item::print();
    std::cout << ", "<< (isALaptop ? "Laptop" : "Desktop") << ", "<<cpu<<std::endl;
}
// void Computer::printConnected() const
//{
//    std::cout<<"There are "<<devices.size()<<"connections to";
//    this->print();
//    for (const auto& device : devices)
//    {
//       // PeripheralDevice::printDevice(device);
//       // device->print();
//    }
//
//}
void Computer::printConnected() const
{
    std::cout << "There are " << devices.size() << " connections to this computer: ";
    this->print(); // Print the computer details
    for (const auto& device : devices) {
        device->print(); // Call the print method of each PeripheralDevice
    }
}
int Computer::getNumOfPorts() const
{
    return numOfPorts;
}
int Computer::getDevicesCounter() const
{
    return devicesCounter;
}
const std::vector<std::shared_ptr<PeripheralDevice>>& Computer::getDevices() const
{
    return devices;
}
std::vector<std::shared_ptr<PeripheralDevice>>& Computer::getDevices()
{
    return devices;
}


//template<typename T>
//bool Computer::hasDeviceOfType(const T& device) const
//{
//    for (const auto& d : devices)
//    {
//        if(d->getType()=="!")
//            return false;
//    }
//    return false;
//}
//std::ostream& operator<<(std::ostream& os, const Computer& computer)
//{
//    os << static_cast<const Item&>(computer);
//    std::string lapType= computer.isALaptop ? "Laptop" : "Desktop";
//    os << ", " << lapType << ", " << computer.cpu;
//    return os;
//}