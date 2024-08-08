#pragma once
#include <string>
#include "Item.h"
#include <vector>
#include <memory>

class Branch
{
protected:
    std::vector<std::shared_ptr<Item>> catalog;
    std::string location;
    int itemCount;
    const int capacity;
    int itemsSum;
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

    static std::vector<Item*> convertToRawPointers(const std::vector<std::shared_ptr<Item>>& sharedCatalog) ;

    template<class T>
            T* giveMeFinest(const T* subItem) const;


    ~Branch() =default;
};


template<class T>
T* Branch::giveMeFinest(const T* subItem) const
{
    T* finest = nullptr;

    for (const auto& item : catalog)
    {
        if (typeid(*item) == typeid(*subItem))
        {
            T* castedItem = dynamic_cast<T*>(item.get());
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
