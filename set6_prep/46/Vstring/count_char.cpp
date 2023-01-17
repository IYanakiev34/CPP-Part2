#include "Vstring.ih"

size_t Vstring::countChar(const std::string &str, Vstring::CharMap &cmap,
                          bool (*accept)(char, CharMap &))
{
    return count_if(str.begin(), str.end(), [&](char ch)
    {
        return accept(ch, cmap);
    });
}
