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

void PeripheralDevice::connect(Computer& computer)
{
    std::shared_ptr<Computer> sharedComputer = computer.shared_from_this();
    std::cout << static_cast<std::string>(*this) + " is connecting to computer: " + static_cast<std::string>(computer) << std::endl;
    if (deviceExistsInComputer(computer, *this))
        return;//device already exist, do nothing
     if(computerCount>=2 || !this->hasDeviceOfType(computer) || computer.getNumOfPorts()<=computer.getDevicesCounter())
     {
         throw ConnectError();
     }

    computer.getDevices().push_back(std::shared_ptr<PeripheralDevice>(this));//or do we have to make shared? computer.getDevices().push_back(shared_from_this());
    connectedComputers.push_back(sharedComputer); //
    ++computerCount;

}

void PeripheralDevice::disconnect()
{
    for (auto it = connectedComputers.begin(); it != connectedComputers.end();)
    {
        if (auto computer = it->lock()) //convert to shared
        {
            auto& devices = computer->getDevices();
            //find the device from the computers vector using lambds func
            auto deviceIt = std::remove_if(devices.begin(), devices.end(),
                                           [this](const std::shared_ptr<PeripheralDevice>& d)
                                           {
                                               return d.get() == this;
                                           });
            //remove the device from comp vector
            if (deviceIt != devices.end()) {
                devices.erase(deviceIt, devices.end());
                std::cout << "Disconnected from " << static_cast<std::string>(*computer) << std::endl;
            }
            //remove the connected Computers of the device
            it = connectedComputers.erase(it);
        } else {
            ++it;
        }
    }
    computerCount = 0;
    std::cout << "Device disconnected from all computers." << std::endl;
}






PeripheralDevice::operator std::string() const
{
    return Item::operator std::string()+", "+(isWireless?"Wireless":"Wired")+", "+color;
}
void PeripheralDevice::print() const
{
  Item::print();
    std::cout << "Peripheral: " << color << ", " << (isWireless ? "Wireless" : "Wired") << std::endl;
}
template<class T>
void PeripheralDevice::printDevice(const std::shared_ptr<T> &ptr)
{

}
int PeripheralDevice::getCompCounter() const
{
    return computerCount;
}
// int PeripheralDevice::getCompCounter() const
//{
//    return computerCount;
//}
