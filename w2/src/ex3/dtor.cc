#include "dummy.h"

Dummy::~Dummy()
{
    std::cout << "Dummy destructor called for object: " << d_name << "\n";
}