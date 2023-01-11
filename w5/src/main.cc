#include "main.ih"

void usage()
{
    char const info[] = R"(Please specify the amount of words you wish to enter!)";
    std::cout << info << "\n";
}

void usage1()
{
    char const info[] = R"(Please specify a file!)";
    std::cout << info << "\n";
}

int main(int argc, char **argv)
{
    // Exercise 33
    /* I THINK I FIXED HIS COMPLAINTS  although some of them were pretty stupid
    if (argc < 2 || (argc == 2 && argv[1] == "-h"))
    {
        usage();
        return 1;
    }

    std::size_t const wordCount = std::stoull(argv[1]);
    std::multiset<std::string> words;

    scanSet(words, wordCount, std::cin);

    printSet(words, std::cout);
    */

    // Exercise 34
    // I think i fixed his issues for this one yet again some of them useless but whatever
    /*
    if (argc < 2 || (argc == 2 && argv[1] == "-h"))
    {
        usage();
        return 1;
    }

    std::size_t const wordCount = std::stoull(argv[1]);
    std::map<std::string, int> words;

    scanMap(words, wordCount, std::cin);

    printMap(words, std::cout);
    */
}
