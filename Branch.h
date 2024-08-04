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
public:
    Branch(const std::string& location="~", const int& capacity=0);
    void addItem( const std::shared_ptr<Item>& newItem);
    std::vector<Item*> getCatalog(int&) const;
    std::string getLocation() const;
    void setLocation(const std::string&);
    Item* removeItem(const int& id);
    std::vector<Item*> convertToRawPointers(const std::vector<std::shared_ptr<Item>>& sharedCatalog) const;

    template<class T>
    T& giveMeFinest(const T& subItem)const;


    ~Branch() =default;
};

