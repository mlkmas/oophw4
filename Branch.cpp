#include "Branch.h"
#include <algorithm>
#include <exception>
#include <stdexcept>

Branch::Branch(const std::string& location, const int& capacity):
        location(location),itemCount(0),capacity(capacity)
{
}

void Branch::addItem(const std::shared_ptr<Item>& newItem)
{
    if(itemCount==capacity)
        throw  std::runtime_error("FullCatalogError");

    /* chatgpt suggested code: to check in case of error
     *    auto it = std::find_if(catalog.begin(), catalog.end(),
                           [id](const std::shared_ptr<Item>& item) { return item->getId() == id; });
    */
    auto it = std::find(catalog.begin(), catalog.end(), newItem);
    if (it != catalog.end())
        throw std::runtime_error("ExistingItemError");

    catalog.push_back(newItem);
    itemCount++;

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
        throw std::runtime_error("NonExistingItemError");
}
std::vector<Item*> Branch::convertToRawPointers(const std::vector<std::shared_ptr<Item>>& sharedCatalog) const
{
    std::vector<Item*> norCatalog;
    for (const auto& item : sharedCatalog) {
        norCatalog.push_back(item.get());
    }
    return norCatalog;
}
std::vector<Item*> Branch::getCatalog(int& num) const
{
    num = itemCount;
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
        throw std::runtime_error("Trying to get an item with a non existing type");
    }
            return finest;
}
