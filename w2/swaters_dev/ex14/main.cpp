#include <iostream>
#include "ShowExcepts.h"

int main()
{
    try
    {
        ShowExcepts([]() { throw 1; }, 1).asNoexcept();
    }
    catch (...) // can catch when argument disables noexcept, but never otherwise
    {
        std::cout << "caught" << std::endl;
    }
}
