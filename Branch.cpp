#include "Branch.h"
#include <algorithm>
#include <iostream>
#include "HWExceptions.h"

Branch::Branch(const std::string& location, const int& capacity):
        location(location),itemCount(0),capacity(capacity),itemsSum(0)
{
}
Branch::Branch(const Branch &other):location(other.location),capacity(other.capacity)
{
    catalog.reserve(other.catalog.size());
    for (const auto& item : other.catalog)
    {
        catalog.push_back(item->clone());
    }
}

Branch::~Branch()
{
    for (auto item : catalog)
    {
        delete item;
    }
}
Branch&  Branch::operator=(const Branch& other)
{
    if (this == &other)
    {
        return *this;
    }
    for (auto item : catalog)
    {
        delete item;
    }
    catalog.clear();
    catalog = other.catalog;
    location = other.location;
    itemCount = other.itemCount;
    catalog.reserve(other.catalog.size());
    for (const auto& item : other.catalog)
    {
        catalog.push_back(item->clone());
    }


    return *this;
}
int Branch::getItemCount() const {
    return itemCount;
}
void Branch::addItem( Item* newItem)
{
    if (itemCount == capacity)
        throw FullCatalogError();
    auto it = std::find(catalog.begin(), catalog.end(), newItem);
    if (it != catalog.end())
        throw ExistingItemError();
    catalog.push_back(newItem);
    itemCount++;
    itemsSum += newItem->getPrice();

}


std::string Branch::getLocation() const
{
    return location;
}

void Branch::setLocation(const std::string& location)
{
    this->location = location;
}

Item* Branch::removeItem(const int& id)
{
    auto it = std::find_if(catalog.begin(), catalog.end(), [id](Item* item)
    {
        return item->getId() == id;
    });

    if (it != catalog.end())
    {
        Item* item = *it;
        catalog.erase(it);
        itemCount--;
        itemsSum-=item->getPrice();
        return item;
    }

    throw NonExistingItemError();
}

//std::vector<Item*> Branch::convertToRawPointers(const std::vector<std::shared_ptr<Item>>& sharedCatalog)
//{
//    std::vector<Item*> norCatalog;
//    for (const auto& item : sharedCatalog) {
//        norCatalog.push_back(item.get());
//    }
//    return norCatalog;
//}
std::vector<Item*> Branch::getCatalog() const
{
    return catalog;
}

int Branch::getItemSum()
{
    return itemsSum;
}
const int Branch::getItemSum() const
{
    return itemsSum;
}
void Branch::setItemSum(int price)
{
    itemsSum+=price;
}
