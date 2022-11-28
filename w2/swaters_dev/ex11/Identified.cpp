//
// Created by Alex Swaters on 11/28/2022.
//

#include <iostream>
#include "Identified.h"

int Identified::nextId = 0;

Identified::Identified(int id)
: id(id)
{}

void Identified::showId() const
{
    std::cout << "ID: " << id << '\n';
}

Identified::Identified(const Identified &other)
{
    id = other.id + 1;
}
