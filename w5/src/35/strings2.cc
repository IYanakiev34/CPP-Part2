#include "strings.ih"

Strings::Strings(std::size_t size, std::string const &word)
{
    d_str.reserve(size);

    for (std::size_t pos = 0; pos != size; ++pos)
    {
        d_str.push_back(word);
    }
}