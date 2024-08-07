#include "MainOffice.h"
#include <map>
#include <string>
#include <memory>

MainOffice &MainOffice::getInstance()
    {
        static MainOffice instance;
        return instance;
    }

void MainOffice::addBranch(const std::string &location, int capacity)
{
    branches.try_emplace

}