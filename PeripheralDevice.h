#pragma once
#include "Item.h"
#include <vector>
#include <memory>
#define TWO_COMPUTERS 2
enum class DeviceType{
    Keyboard,
    Mouse,
    Tablet
};

class Computer;

class PeripheralDevice :public virtual Item
{
protected:
    std::string color;
    bool isWireless;
    DeviceType type;
    std::vector<Computer*> connectedComputers;
    int computerCount;
public:
    PeripheralDevice(int, const std::string&, const std::string&, bool,DeviceType type);
   virtual ~PeripheralDevice()noexcept;
   PeripheralDevice(const PeripheralDevice &other);
   void perfomCleanUp();
    std::string getColor() const;
    bool getIsWireless() const;
    int getCompCounter()const;
    void setColor(const std::string&);
    void setIsWireless(bool);
    DeviceType  getType()const;
    operator std::string() const override;
    virtual void connect( Computer&);
    virtual void disconnect();
    virtual void print() const override;
    virtual PeripheralDevice* clone() const override;
    template<class T>
    static void printDevice(const std::shared_ptr<T>& ptr);
    static bool deviceExistsInComputer(const Computer& computer, const PeripheralDevice& device);
    const bool hasDeviceOfType(const Computer& computer)const;

};

