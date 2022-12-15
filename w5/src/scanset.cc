#include "main.ih"

void scanSet(std::multiset<std::string> &words, std::size_t size)
{
    std::string tmp;

    // Postfix is used with intent
    // otherwise we will get wordCount - 1 words scanned
    while (size-- > 0)
    {
        std::cin >> tmp;
        words.insert(std::move(tmp));
    }
}