#include "main.ih"

void printMap(std::map<std::string, int> &words)
{
    std::map<std::string, int>::const_iterator wordIter = words.cbegin();

    for (; wordIter != words.cend(); ++wordIter)
        std::cout << wordIter->first << " : " << wordIter->second << "\n";
}