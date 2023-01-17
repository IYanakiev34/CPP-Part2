#include "Vstring.ih"

size_t Vstring::count(Vstring::CharMap &cmap, bool (*accept)(char, CharMap &))
{
    size_t total = 0;
    std::for_each(begin(), end(), [&](std::string const &str)
    {
        total += countChar(str, cmap, accept);
    });
    return total;
}