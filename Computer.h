#pragma once
#include "Item.h"
#include <vector>
#include <memory>

class PeripheralDevice;

class Computer :public Item
{
    std::string cpu;
    bool isALaptop;
    const int numOfPorts;
    std::vector<std::shared_ptr<PeripheralDevice>> devices;
public:
    Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop,const int numOfPorts);
    void setCpu(const std::string&);
    void setIsALaptop(bool);
    std::string getCpu() const;
    bool getIsALaptop() const;
    operator std::string() const;
    friend std::ostream& operator<<(std::ostream& os, const Computer& computer);
};

