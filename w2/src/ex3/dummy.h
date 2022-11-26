#ifndef INCLUDED_DUMMY_H
#define INCLUDED_DUMMY_H

#include <iostream>
#include <string>

class Dummy
{
    std::string d_name;

public:
    Dummy(std::string &name);
    Dummy(Dummy const &other);
    ~Dummy();
};

#endif