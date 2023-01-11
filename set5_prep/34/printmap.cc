#include "main.ih"

void printMap(std::map<std::string, int> const &words, std::ostream &out)
{
    for (auto const &word : words)
        out << word.first << ":" << word.second << "\n";
}