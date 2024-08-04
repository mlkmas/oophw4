#ifndef HWEXCEPTIONS_H
#define HWEXCEPTIONS_H
#include <stdexcept>
#include <string>
#include <cstring>

class ExistingBranchInsertError:public std::exception
{
public:

    explicit ExistingBranchInsertError()=default;
    ExistingBranchInsertError(const ExistingBranchInsertError&)=default;
    ExistingBranchInsertError& operator=(const ExistingBranchInsertError&)=default;
    ~ExistingBranchInsertError()=default;
    virtual const char* what() const noexcept override
    {
        return "Trying to add a branch with an already existing location";
    }

};


#endif