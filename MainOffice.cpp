#include "MainOffice.h"
#include <map>
#include <string>
#include <memory>
#include <algorithm>

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
bool MainOffice::compare(const std::pair<std::string, Branch>& a, const std::pair<std::string, Branch>& b)
{
    return a.first < b.first;
}
bool MainOffice::comparePrices(const std::pair<std::string, Branch> &a, const std::pair<std::string, Branch> &b)
{
   if(a.second.getItemSum() == b.second.getItemSum())
      return a.first < b.first;

   return a.second.getItemSum() < b.second.getItemSum();
}
//std::vector<std::pair<std::string, Branch>> MainOffice::sortMapInVector()const
//{
//    std::vector<std::pair<std::string, Branch>> pairVec(branches.begin(), branches.end());
//    std::sort(pairVec.begin(), pairVec.end(), compare);
//
//    return pairVec;
//}
//


//std::vector<std::pair<std::string,Branch>> MainOffice::sortMapInVector(std::map<std::string, Branch> &other)
//{
//    std::vector<std::pair <std::string, Branch> > pairVec;
//
//    for ( auto& it : other ) {
//        pairVec.push_back( it );
//    }
//
//    std::sort( pairVec.begin(), pairVec.end(), compare);
//
//}
void MainOffice::printBranchesByLocation(void (*printCatalog)(const Branch &)) const
{
    std::vector<std::pair<std::string, Branch>> pairVec(branches.begin(), branches.end());
    std::sort(pairVec.begin(), pairVec.end(), MainOffice::compare);
    for(const auto& it: pairVec)
    {
        printCatalog(it.second);
    }
}
void MainOffice::printBranchesByValue(void (*printCatalog)(const Branch &)) const
{
    std::vector<std::pair<std::string, Branch>> pairVec(branches.begin(), branches.end());
    std::sort(pairVec.begin(), pairVec.end(), MainOffice::comparePrices);

    for (const auto& it : pairVec)
    {
        printCatalog(it.second);
    }
}