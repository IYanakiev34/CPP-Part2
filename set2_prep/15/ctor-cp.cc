#include "dummy.ih"

Dummy::Dummy(Dummy const &other)
{
    d_name = other.d_name + " copy";
    std::cout << "Dummy copy called"
              << " New name is: " << d_name << "\n";
}