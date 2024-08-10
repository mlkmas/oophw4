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


class NonExistingBranchRemoveError:public std::exception
{
public:

    explicit NonExistingBranchRemoveError()=default;
    NonExistingBranchRemoveError(const NonExistingBranchRemoveError&)=default;
    NonExistingBranchRemoveError& operator=(const NonExistingBranchRemoveError&)=default;
    ~NonExistingBranchRemoveError()=default;
    virtual const char* what() const noexcept override
    {
        return "Trying to remove a branch with a non existing location";
    }

};

class NonExistingBranchRetrieveError:public std::exception
{
public:

    explicit NonExistingBranchRetrieveError()=default;
    NonExistingBranchRetrieveError(const NonExistingBranchRetrieveError&)=default;
    NonExistingBranchRetrieveError& operator=(const NonExistingBranchRetrieveError&)=default;
    ~NonExistingBranchRetrieveError()=default;
    virtual const char* what() const noexcept override
    {
        return "Trying to retrieve a branch with a non existing location";
    }

};

class ExistingItemError :public std::exception
{
public:

    explicit ExistingItemError ()=default;
    ExistingItemError (const ExistingItemError &)=default;
    ExistingItemError & operator=(const ExistingItemError &)=default;
    ~ExistingItemError ()=default;
    virtual const char* what() const noexcept override
    {
        return "Trying to add an item with an id already in the catalog ";
    }

};

class FullCatalogError:public std::exception
{
public:

    explicit FullCatalogError()=default;
    FullCatalogError(const FullCatalogError&)=default;
    FullCatalogError& operator=(const FullCatalogError&)=default;
    ~FullCatalogError()=default;
    virtual const char* what() const noexcept override
    {
        return "Trying to add an item to a full catalog ";
    }

};

class NonExistingItemError:public std::exception
{
public:

    explicit NonExistingItemError()=default;
    NonExistingItemError(const NonExistingItemError&)=default;
    NonExistingItemError& operator=(const NonExistingItemError&)=default;
    ~NonExistingItemError()=default;
    virtual const char* what() const noexcept override
    {
        return "Trying to remove an item with a non existing id";
    }

};

class NoneExistingItemTypeError:public std::exception
{
public:

    explicit NoneExistingItemTypeError()=default;
    NoneExistingItemTypeError(const NoneExistingItemTypeError&)=default;
    NoneExistingItemTypeError& operator=(const NoneExistingItemTypeError&)=default;
    ~NoneExistingItemTypeError()=default;
    virtual const char* what() const noexcept override
    {
        return "Trying to get an item with a non existing type";
    }

};

class ConnectError:public std::exception
{
public:

    explicit ConnectError()=default;
    ConnectError(const ConnectError&)=default;
    ConnectError& operator=(const ConnectError&)=default;
    ~ConnectError()=default;
    virtual const char* what() const noexcept override
    {
        return "Failed connection attempt";
    }

};

#endif