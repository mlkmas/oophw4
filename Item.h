#pragma once
#include <string>
#include "HWExceptions.h"
class Item
{
    int price;
    std::string manufacturer;
    const int id;
    static int id_counter;
public:
    Item(int price, std::string manufacturer);
    void setPrice(int);
    void setManufacturer(const std::string&);
    int getPrice() const;
    std::string getManufacturer() const;
    virtual operator std::string() const = 0;
    int getId() const;
    static bool itemPtrCompare(const Item *ptr1, const Item *ptr2);

    virtual ~Item();
    virtual void print()const;

    bool operator==(const Item& other) const;

  //  friend std::ostream& operator<<(std::ostream& os, const Item& item) ;
};

