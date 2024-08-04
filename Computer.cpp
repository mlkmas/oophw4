#include "Computer.h"
Computer::Computer(int price, const std::string& manufacturer, const std::string& cpu, bool isALaptop):
        Item(price,manufacturer),cpu(cpu),isALaptop(isALaptop){}
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