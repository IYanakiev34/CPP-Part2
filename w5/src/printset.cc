#include "main.ih"

void printSet(std::multiset<std::string> const &words, std::ostream &out)
{
    for (std::string const &i : words)
        out << i << "\n";
}
