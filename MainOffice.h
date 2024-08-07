#ifndef UNTITLED18_MAINOFFICE_H
#define UNTITLED18_MAINOFFICE_H
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include "Branch.h"

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
    void removeBranch(std::string &location);
    const std::string& getBranch(const std::string &location)const;
     void printBranchesByLocation(void (*printCatalog)(const Branch&))const;
    void printBranchesByValue(void (*printCatalog)(const Branch&))const;







};






#endif //UNTITLED18_MAINOFFICE_H
