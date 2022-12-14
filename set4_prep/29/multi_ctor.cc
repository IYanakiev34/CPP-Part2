#include "29.ih"

Multi::Multi() : Basic(10)
{
    std::cout << static_cast<Basic *>(this) << "\n";
    std::cout << "Multi constructor called\n";
}
