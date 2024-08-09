#include "MainOffice.h"
#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <iostream>

MainOffice &MainOffice::getInstance()
{
    static MainOffice instance;
    return instance;
}

void MainOffice::addBranch(const std::string &location, int capacity)
{
    if(!(branches.try_emplace(location,Branch(location,capacity)).second))
        throw ExistingBranchInsertError();
}
void MainOffice::removeBranch(const std::string &location)
{
    if(!(branches.erase(location)))
        throw NonExistingBranchRemoveError();
}

const Branch &MainOffice::getBranch(const std::string &location) const
{
    auto result=branches.find(location);
    if(result==branches.end())
        throw NonExistingBranchRetrieveError();
    return result->second;
}
Branch &MainOffice::getBranch(const std::string &location)
{
    auto result=branches.find(location);
    if(result==branches.end())
        throw NonExistingBranchRetrieveError();
    return result->second;
}
bool MainOffice::compare(Branch* a, Branch* b)
{
    return a->getLocation() < b->getLocation();
}
bool MainOffice::comparePrices(Branch* a, Branch* b)
{
    if(a->getItemSum() == b->getItemSum())
        return a->getLocation() < b->getLocation();

    return a->getItemSum() < b->getItemSum();
}
void MainOffice::printBranchesByLocation(void (*printCatalog)(const Branch &)) const
{
    std::vector<Branch*> sortedBranches;
    for (const auto& entry : branches)
    {
        sortedBranches.push_back(const_cast<Branch*>(&entry.second));
    }
    std::cout<<"There are "<<branches.size()<<" branches in Main Office:"<<std::endl;
    std::sort(sortedBranches.begin(), sortedBranches.end(), compare);
    for (const auto& branch : sortedBranches)
    {
        std::cout<<branch->getLocation()<<" : Item count: "<<branch->getItemCount()<<", Total Value: "<<branch->getItemSum()<<std::endl;
        printCatalog(*branch);
    }
}

void MainOffice::printBranchesByValue(void (*printCatalog)(const Branch &)) const
{
    std::vector<Branch*> sortedBranches;
    std::cout<<"There are "<<branches.size()<<" branches in Main Office:"<<std::endl;
    for (const auto& entry : branches)
    {
        sortedBranches.push_back(const_cast<Branch*>(&entry.second));
    }

    std::sort(sortedBranches.begin(), sortedBranches.end(), comparePrices);
    for (const auto& branch : sortedBranches)
    {
        std::cout<<branch->getLocation()<<" : Item count: "<<branch->getItemCount()<<", Total Value: "<<branch->getItemSum()<<std::endl;

        printCatalog(*branch);
    }
}
