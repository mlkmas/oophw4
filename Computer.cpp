#include <iostream>
#include "Computer.h"
#include "PeripheralDevice.h"
Computer::Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop,const int numOfPorts):
        Item(price,manufacturer),cpu(cpu),isALaptop(isALaptop),numOfPorts(numOfPorts),devicesCounter(0){}
void Computer::setCpu(const std::string& cpu)
{
    this->cpu = cpu;
}
Computer::Computer(const Computer &other) : Item(other),cpu(other.cpu),isALaptop(other.isALaptop),
numOfPorts(other.numOfPorts),devicesCounter(other.devicesCounter)
{
    devices.reserve(other.devices.size());
    for (const PeripheralDevice* d : other.devices) {
        devices.push_back(d->clone()); // Clone each device object
    }
}
void Computer::setIsALaptop(bool isALaptop)
{
    this->isALaptop = isALaptop;
}
void Computer::setDevicesCounter(int num)
{
    devicesCounter+=num;
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
    return Item::operator std::string() + ", " + (isALaptop ? "Laptop" : "Desktop") + ", " + cpu;
}
void Computer::print() const
{
    Item::print();
    std::cout << ", "<< (isALaptop ? "Laptop" : "Desktop") << ", "<<cpu<<std::endl;
}

void Computer::printConnected() const
{
    std::cout << "There are " << devices.size() << " connections to ";//or devicesCounter instead od devices.size()
    this->print();
    for (const auto& device : devices)
    {
        device->print();
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
const std::vector<PeripheralDevice*>& Computer::getDevices() const
{
    return devices;
}
std::vector<PeripheralDevice*>& Computer::getDevices()
{
    return devices;
}

Computer *Computer::clone() const
{
    return new Computer(*this);
}

