#include "smart_str.ih"

SmartStrings &SmartStrings::operator+=(std::string const &word)
{
    d_str.push_back(std::make_shared<std::string>(word));
    return *this;
}