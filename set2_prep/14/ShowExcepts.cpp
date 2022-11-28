#include <exception>
#include "ShowExcepts.h"

ShowExcepts::ShowExcepts(void (*func)(), int value = 1)
: func(func)
, val(value) // set value to 1 to simulate noexcept being active by default
{}

void ShowExcepts::asNoexcept()
{
    if (val != 0) // simulate optional noexcept argument
    {
        try // noexcept effectively wraps body in a try
        {
            func();
        }
        catch (...) // when it throws (anything) it calls terminate
        {
            std::terminate();
        }
        return;
    }
    func(); // when noexcept is not active, this behaves like a normal function
}