#ifndef UNTITLED18_PERIPHERALDEVICE_H
#define UNTITLED18_PERIPHERALDEVICE_H
#include "Computer.h"
class PeripheralDevice :public Item
{
    std::string color;
    bool isWireless;
public:
    PeripheralDevice(int, const std::string&, const std::string&, bool);
    std::string getColor() const;
    bool getIsWireless() const;
    void setColor(const std::string&);
    void setIsWireless(bool);
    operator std::string() const;
    virtual void connect(const Computer&) = 0;
};


#endif //UNTITLED18_PERIPHERALDEVICE_H
