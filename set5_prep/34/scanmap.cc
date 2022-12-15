#include "main.ih"

void scanMap(std::map<std::string, int> &words, std::size_t size)
{
    std::string tmp;
    // Postfix otherwise will scan one elements less
    while (size-- > 0)
    {
        std::cin >> tmp;
        std::map<std::string, int>::iterator wordsIter = words.find(tmp);

        if (wordsIter != words.end())
        {
            wordsIter->second++;
        }
        else
        {
            words.insert(std::pair<std::string, int>{std::move(tmp), 1});
        }
    }
}