#include <iostream>
#include <set>
#include <string>

void usage()
{
    char const info[] = R"(Please specify the amount of words you wish to eneter!)";
    std::cout << info << "\n";
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        usage();
        return 0;
    }

    std::size_t wordCount = atoi(argv[1]);
    std::multiset<std::string> words;

    std::string tmp;

    // Postfix is used with intent
    // otherwise we will get wordCount - 1 words scanned
    while (wordCount-- > 0)
    {
        std::cin >> tmp;
        words.insert(std::move(tmp));
    }

    std::multiset<std::string>::const_iterator wordsIter = words.cbegin();
    for (; wordsIter != words.cend(); ++wordsIter)
        std::cout << *wordsIter << "\n";

    return 0;
}