#pragma once

#include "presenter/viewmodels/iViewmodel.hpp"

#include <vector>

namespace vm
{
    template <typename T>
    struct vector: public IViewmodel, public std::vector<T>
    {};

    template <typename T>
    struct data: public IViewmodel
    {
        data(T d): d{d} {}
        const T &get() const {return d;}
        void set(T d) {this->d = d;}

    private:
        T d;
    };
}
