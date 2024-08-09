#pragma once
#include "PeripheralDevice.h"
class Mouse :
        public PeripheralDevice
{
    int dpi;
public:
    Mouse(int, const std::string&, const std::string&, bool, int);
    int getDpi() const;
    void setDpi(int);
  void connect( Computer&) override;
    operator std::string() const override;
    virtual void print() const override;
    Mouse(const Mouse& other);
     Mouse* clone() const override;
};
