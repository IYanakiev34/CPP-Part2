#include <exception>
#include <iostream>
#include "ShowExcepts.h"

ShowExcepts::ShowExcepts(void (*func)(), int value = 1)
: func(func)
, val(value) // set value to 1 to simulate noexcept being active by default
{}

void ShowExcepts::asNoexcept()
{
    if (val == 1) // simulate optional noexcept argument
    {
        try // noexcept effectively wraps body in a try
        {
            func();
        }
        catch (...) // when it throws (anything) it calls terminate
        {
            std::terminate();
        }
    }
    else // if the optional argument doesn't evaluate to true, then noexcept is ignored
    {
        std::cout << "noexcept ignored" << std::endl;
        func();
    }
}