#include "strings.ih"

Strings &Strings::operator+=(std::string const &other)
{
    d_str.push_back(other);
    return *this;
}