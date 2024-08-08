#include "Branch.h"
#include <algorithm>
#include "HWExceptions.h"

Branch::Branch(const std::string& location, const int& capacity):
        location(location),itemCount(0),capacity(capacity)
{
}
Branch::Branch(const Branch &other):location(other.location),capacity(other.capacity)
{}
Branch&  Branch::operator=(const Branch& other){
    if (this == &other) {
        return *this;
    }

    catalog = other.catalog;
    location = other.location;
    itemCount = other.itemCount;
    return *this;
}
void Branch::addItem( Item* newItem)
{
    if(itemCount==capacity)
        throw  FullCatalogError();

    /* chatgpt suggested code: to check in case of error
     *    auto it = std::find_if(catalog.begin(), catalog.end(),
                           [id](const std::shared_ptr<Item>& item) { return item->getId() == id; });
    */
    std::shared_ptr<Item> shared_ptr(newItem);
    auto it = std::find(catalog.begin(), catalog.end(), shared_ptr);
    if (it != catalog.end())
        throw ExistingItemError();

    catalog.push_back(shared_ptr);
    itemCount++;
    itemsSum+=newItem->getPrice();

}


std::string Branch::getLocation() const
{
    return location;
}

void Branch::setLocation(const std::string& location)
{
    this->location = location;
}

//Branch::~Branch()
//{
//    //shared ptr will handle the deleting
//    //for (int i = 0; i < itemCount; i++) delete catalog[i];
//}
 Item* Branch::removeItem(const int& id)
{
        auto it = std::find_if(catalog.begin(), catalog.end(),[id](const std::shared_ptr<Item>& item)
        {return item->getId() == id;});
        if (it != catalog.end())
        {
            std::shared_ptr<Item> item = *it;
            catalog.erase(it);
            itemCount--;
            return item.get();
        }
        throw NonExistingItemError();
}
std::vector<Item*> Branch::convertToRawPointers(const std::vector<std::shared_ptr<Item>>& sharedCatalog)
{
    std::vector<Item*> norCatalog;
    for (const auto& item : sharedCatalog) {
        norCatalog.push_back(item.get());
    }
    return norCatalog;
}
std::vector<Item*> Branch::getCatalog() const
{
    return convertToRawPointers(catalog) ;
}
template<class T>
T& Branch::giveMeFinest(const T &subItem) const
{
    T *finest= nullptr;
    for(const auto &item :catalog)
    {

        if(typeid(*item) == typeid(T))
        {
            T* castedItem=dynamic_cast<T*>(item.get());
            if(castedItem && (!finest || castedItem->getPrice() > finest->getPrice()))
               finest = item;
        }

    }
    if (!finest)
    {
        throw NoneExistingItemTypeError();
    }
            return finest;
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
