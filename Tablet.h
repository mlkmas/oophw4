#pragma once
#include "PeripheralDevice.h"
#include "Computer.h"
#define ONE_COMPUTER 1
class Tablet :public PeripheralDevice ,public Computer
{
private:
    int screenSize;


public:
    Tablet(int price, const std::string& manufacturer, const std::string& color,const std::string &cpu,bool,int screen);
    virtual void connect(Computer& computer) override;
    void disconnect() override;
    virtual void print() const override;
   operator std::string() const override;
   Tablet(const Tablet& other);
   Tablet* clone() const override;
};
