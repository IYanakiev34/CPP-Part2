#include "dummy.ih"

Dummy::Dummy(std::string &name)
{
    d_name = name;
    std::cout << "Constructor called\n";
}