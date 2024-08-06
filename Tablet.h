#pragma once
#include "PeripheralDevice.h"
class Tablet :public PeripheralDevice
{
private:
    int screenSize;


public:
    Tablet(int price, const std::string& manufacturer, const std::string& color,const std::string &cpu,bool,int screen);
    virtual void connect(Computer&) override;
//    operator std::string() const override;
};
