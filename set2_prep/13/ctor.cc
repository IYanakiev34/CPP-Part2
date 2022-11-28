#include "maxfour.ih"

size_t MaxFour::d_Objects = 0;
MaxFour::MaxFour()
{
    if (++d_Objects == 4)
        throw std::string{"max objects reached"};
}