#pragma once

#include <string>

struct IViewmodel
{
    virtual ~IViewmodel() = default;
    std::string label;
protected:
    static std::size_t nextId;
};
