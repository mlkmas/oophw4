#pragma once
#include "Item.h"
class Computer :
        public Item
{
    std::string cpu;
    bool isALaptop;
public:
    Computer(int, const std::string&, const std::string&, bool);
    void setCpu(const std::string&);
    void setIsALaptop(bool);
    std::string getCpu() const;
    bool getIsALaptop() const;
    operator std::string() const;
};

