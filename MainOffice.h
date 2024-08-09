#ifndef UNTITLED18_MAINOFFICE_H
#define UNTITLED18_MAINOFFICE_H
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include "Branch.h"
#include <vector>
#include <memory>

class MainOffice
{
private:
    std::map<std::string ,Branch> branches;
    MainOffice()=default;
    MainOffice(MainOffice &other)=delete;
    MainOffice& operator=(MainOffice &other)=delete;


public:
    static MainOffice& getInstance();
    void addBranch(const std::string &location, int capacity);
    void removeBranch(const std::string &location);
    const Branch& getBranch(const std::string &location)const;
    void printBranchesByLocation(void (*printCatalog)(const Branch&))const;
    void printBranchesByValue(void (*printCatalog)(const Branch&))const;
    Branch& getBranch(const std::string &location);
    static bool compare(Branch* a, Branch* b);
    static bool comparePrices(Branch* a, Branch* b);
    //std::vector<std::pair<std::string,Branch>> sortMapInVector()const;







};






#endif //UNTITLED18_MAINOFFICE_H