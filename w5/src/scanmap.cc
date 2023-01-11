#include "main.ih"

void scanMap(std::map<std::string, int> &words, std::size_t const size, std::istream &in)
{
    std::string currWord{};

    for (std::size_t idx = 0; idx != size; ++idx)
    {
        in >> currWord;
        std::map<std::string, int>::iterator wordIter = words.find(currWord);

        if (wordIter != words.end())
            ++wordIter->second;
        else
            words.insert({currWord, 1});
    }
}