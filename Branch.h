#pragma once
#include <string>
#include "Item.h"
#include <vector>
#include <memory>

class Branch
{
protected:
    std::vector<Item*> catalog;
    std::string location;
    int itemCount=0;
    const int capacity;
    int itemsSum=0;
    //Item* finestItem= nullptr;
public:
    Branch(const std::string& location="~", const int& capacity=0);
    Branch(const Branch &other);
    Branch& operator=(const Branch& other);
    void addItem(  Item* newItem);
    std::vector<Item*> getCatalog() const;
    std::string getLocation() const;
    void setLocation(const std::string&);
    Item* removeItem(const int& id);
    const int getItemSum()const;
    int getItemSum();
    void setItemSum(int price);
    int getItemCount()const;

    template<class T>
            T* giveMeFinest(const T* subItem) const;


    ~Branch();
};

template<class T>
T* Branch::giveMeFinest(const T* subItem) const
{
    T* finest = nullptr;

    for (const auto& item : catalog)
    {
        if (typeid(*item) == typeid(*subItem))
        {
            T* castedItem = dynamic_cast<T*>(item);
            if (castedItem && (!finest || castedItem->getPrice() > finest->getPrice()))
                finest = castedItem;
        }
    }

    if (!finest)
    {
        throw NoneExistingItemTypeError();
    }

    return finest;
}