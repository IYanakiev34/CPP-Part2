#include "main.ih"

namespace First
{
    void fun(First::Enum symbol)
    {
        std::cout << "Called from first namespace\n";
    }
}

namespace Second
{
    void fun(First::Enum symbol)
    {
        std::cout << "Called from seocnd namespace\n";
    }
}