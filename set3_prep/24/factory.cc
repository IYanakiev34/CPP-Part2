#include "main.ih"

namespace
{
    std::string s_str;
}

std::string *factory(std::string const &str, size_t count)
{
    s_str = str;
    struct StringPlaceholder : public std::string
    {
        StringPlaceholder() : std::string(s_str) {}
    };
    return new StringPlaceholder[count];
}