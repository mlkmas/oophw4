#include "PeripheralDevice.h"
#include "Computer.h"
#include <iostream>
#include <algorithm>

PeripheralDevice::PeripheralDevice(int price, const std::string& manufacturer, const std::string& color,
                                   bool isWireless,DeviceType type):
        Item(price,manufacturer),color(color),isWireless(isWireless),computerCount(0),type(type){}

void PeripheralDevice::perfomCleanUp()
{
    disconnect();
}

PeripheralDevice::~PeripheralDevice() noexcept
{
    perfomCleanUp();
}

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
DeviceType PeripheralDevice::getType() const
{
    return type;
}

const bool PeripheralDevice::hasDeviceOfType(const Computer& computer)const
{
    for (const auto& d : computer.getDevices())
    {
      if(d->getType()==this->getType())
          return false;

    }
    return true;

}
bool PeripheralDevice::deviceExistsInComputer(const Computer& computer, const PeripheralDevice& device)
{
    for (const auto& d : computer.getDevices()) {
        if (d->getType() == device.getType()) {
            return true;
        }
    }
    return false;
}
void PeripheralDevice::connect(Computer& computer) {
    std::cout << static_cast<std::string>(*this) + " is connecting to computer: " + static_cast<std::string>(computer) << std::endl;
    if (deviceExistsInComputer(computer, *this))
    {
        throw ConnectError();
        return; // Device already exists, do nothing
    }
    if (computerCount >= 2 || !this->hasDeviceOfType(computer) || computer.getNumOfPorts() <= computer.getDevicesCounter()) {
        throw ConnectError();
    }

    computer.getDevices().push_back(this);
    connectedComputers.push_back(&computer);
    ++computerCount;
}
void PeripheralDevice::disconnect() {
    for (auto it = connectedComputers.begin(); it != connectedComputers.end();) {
        Computer* computer = *it;
        if (computer)
        {
            //find the device in the computer and Remove it from the computer's vector
            auto& devices = computer->getDevices();
            for (auto devIt = devices.begin(); devIt != devices.end(); ++devIt)
            {
                if (*devIt == this)
                {
                    devices.erase(devIt);  //is it okay to remove from outside of the class?
                    computer->setDevicesCounter(-1);
                    //std::cout << "Disconnected from " << static_cast<std::string>(*computer) << std::endl;
                    break;
                }
            }
            it = connectedComputers.erase(it);  // Remove the computer from connectedComputers
        } else {
            ++it;
        }
    }
    computerCount = 0;
    //std::cout << "Device disconnected from all computers." << std::endl;
}
PeripheralDevice::PeripheralDevice(const PeripheralDevice &other) : Item(other),color(other.color),isWireless(other.isWireless),type(other.type),computerCount(other.computerCount)
{
    connectedComputers.reserve(other.connectedComputers.size());
    for (const Computer* computer : other.connectedComputers)
    {
        connectedComputers.push_back(computer->clone());
    }
}
PeripheralDevice::operator std::string() const
{
    return Item::operator std::string()+", "+(isWireless?"Wireless":"Wired")+", "+color;
}
void PeripheralDevice::print() const
{
     Item::print();
     std::cout<< ", "<<(isWireless?"Wireless":"Wired")<<", "<<color;
}
template<class T>
void PeripheralDevice::printDevice(const std::shared_ptr<T> &ptr)
{

}
int PeripheralDevice::getCompCounter() const
{
    return computerCount;
}

PeripheralDevice *PeripheralDevice::clone() const
{
    return new PeripheralDevice(*this);
}
// int PeripheralDevice::getCompCounter() const
//{
//    return computerCount;
//}
