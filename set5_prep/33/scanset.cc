#include "main.ih"

void scanSet(std::multiset<std::string> &words, std::size_t const size, std::istream &in)
{
    std::string currWord{};

    for (std::size_t idx = 0; idx != size; ++idx)
    {
        in >> currWord;
        words.insert(currWord);
    }
}