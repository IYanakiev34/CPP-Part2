#include <iostream>
#include "ShowExcepts.h"

int main()
{
    try
    {
        ShowExcepts([]() { throw 1; }, 0).asNoexcept();
    }
    catch (...) // can catch when argument disables noexcept, but never otherwise
    {
        std::cout << "caught" << std::endl;
    }
    return 0;
}
