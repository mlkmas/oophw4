#pragma once
#include <string>
#include "Item.h"
#include <vector>
#include <memory>

class Branch
{
    std::vector<std::shared_ptr<Item>> catalog;
    std::string location;
    int itemCount;
    const int capacity;
    int itemsSum;
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
    T& giveMeFinest(const T& subItem)const;


    ~Branch() =default;
};

