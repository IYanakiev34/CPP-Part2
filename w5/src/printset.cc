#include "main.ih"

void printSet(std::multiset<std::string> &words)
{
    std::multiset<std::string>::const_iterator wordsIter = words.cbegin();
    for (; wordsIter != words.cend(); ++wordsIter)
        std::cout << *wordsIter << "\n";
}