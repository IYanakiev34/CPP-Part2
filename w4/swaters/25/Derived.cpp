//
// Created by Alex Swaters on 12/9/2022.
//

#include "Derived.h"

#include <utility>

Derived::Derived(std::string str)
        : str(std::move(str)) // suggested by clang tidy
{}

void Derived::vHello(std::ostream &out) const
{
    out << str << '\n';
}

