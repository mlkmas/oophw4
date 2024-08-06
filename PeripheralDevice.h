#ifndef UNTITLED18_PERIPHERALDEVICE_H
#define UNTITLED18_PERIPHERALDEVICE_H
#include "Computer.h"

enum class DeviceType{
    Keyboard,
    Mouse,
    Tablet
};
class Computer;

class PeripheralDevice :public Item
{
    std::string color;
    bool isWireless;
    int computerCount;
    DeviceType type;
    std::vector<std::weak_ptr<Computer>> connectedComputers;
public:
    PeripheralDevice(int, const std::string&, const std::string&, bool,DeviceType type);
   virtual ~PeripheralDevice()noexcept;
   void perfomCleanUp();
    std::string getColor() const;
    bool getIsWireless() const;
    int getCompCounter()const;
    void setColor(const std::string&);
    void setIsWireless(bool);
    DeviceType  getType()const;
    operator std::string() const;
    virtual void connect( Computer&);
    virtual void disconnect();
    virtual void print() const override;

    template<class T>
    static void printDevice(const std::shared_ptr<T>& ptr);
    static bool deviceExistsInComputer(const Computer& computer, const PeripheralDevice& device);


    const bool hasDeviceOfType(const Computer& computer)const;
};


#endif //UNTITLED18_PERIPHERALDEVICE_H
