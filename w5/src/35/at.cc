#include "strings.ih"

std::string &Strings::at(std::size_t idx)
{
    if (idx >= 0 && idx <= d_str.size() - 1)
    {
        return d_str[idx];
    }
    else
    {
        throw std::out_of_range("Not valid index");
    }
}