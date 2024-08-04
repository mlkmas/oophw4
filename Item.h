#pragma once
#include <string>

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

    virtual ~Item();

    bool operator==(const Item& other) const;
};

