#pragma once
#include "Item.h"
#include <vector>
#include <memory>

class PeripheralDevice;

class Computer :public virtual Item
{
protected:
    std::string cpu;
    bool isALaptop;
    std::vector<PeripheralDevice*> devices;
    int devicesCounter;
    const int numOfPorts;
public:

    Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop,const int numOfPorts);
    void setCpu(const std::string&);
    Computer(const Computer &other);
    void setIsALaptop(bool);
    std::string getCpu() const;
    bool getIsALaptop() const;
    void setDevicesCounter(int num);
    virtual Computer* clone() const override;
    operator std::string() const override;
     void printConnected()const;
     void print()const override;
     int getNumOfPorts()const;
     int getDevicesCounter()const;
    std::vector<PeripheralDevice*>& getDevices();
   const std::vector<PeripheralDevice*>& getDevices()const;



//    template<typename T>
//    bool hasDeviceOfType(const T& device)const;
   // friend std::ostream& operator<<(std::ostream& os, const Computer& computer);
};
