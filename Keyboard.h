#pragma once
#include "PeripheralDevice.h"
class Keyboard :
        public PeripheralDevice
{
    int numOfKeys;
public:
    Keyboard(int, const std::string&, const std::string&, bool, int);
    int getNumberOfKeys() const;
    void setNumberOfKeys(int);
   void connect( Computer&) override;
    operator std::string() const override;
    virtual void print() const override;
    Keyboard(const Keyboard& other);
     Keyboard* clone() const override;
};

