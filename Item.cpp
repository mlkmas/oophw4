#include "Item.h"
#include <iostream>
int Item::id_counter = 1;
Item::Item(int price, std::string manufacturer):price(price),manufacturer(manufacturer),id(id_counter++)
{
}

void Item::setPrice(int price)
{
    this->price = price;
}

void Item::setManufacturer(const std::string& manufacturer)
{
    this->manufacturer = manufacturer;
}

int Item::getPrice() const
{
    return price;
}

std::string Item::getManufacturer() const
{
    return manufacturer;
}

Item::operator std::string() const
{
    return std::string("id " + std::to_string(id) + ": " + manufacturer + ", " + std::to_string(price) + "$");
}

int Item::getId() const
{
    return id;
}

Item::~Item()
{
    std::cout << "Throwing away an item" << std::endl;
}
bool Item::operator==(const Item& other) const
{
    return id == other.id;
}
bool Item::itemPtrCompare(const Item *ptr1,const Item *ptr2)
{
    return ptr1->id<ptr2->id;

}
void Item::print() const
{
    std::cout << "id " <<id<<": "<<manufacturer<<", "<<price<<"$";
}
//std::ostream& operator<<(std::ostream& os, const Item& item)
//{
//    os << "id " << item.id <<": "<<item.manufacturer<<" "<<item.price<<"$";
//    return os;
//}