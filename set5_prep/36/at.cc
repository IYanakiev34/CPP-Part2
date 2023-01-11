#include "smart_str.ih"

std::shared_ptr<std::string> &SmartStrings::at(std::size_t idx)
{
    if (idx >= 0 && idx <= d_str.size() - 1)
        return d_str[idx];
    else
        throw std::out_of_range("Not valid index!");
}