#include "main.ih"

void usage()
{
    char const info[] = R"(Please specify the amount of words you wish to enter!)";
    std::cout << info << "\n";
}

int main(int argc, char **argv)
{
    // Exercise 33
    /*
    if (argc < 2)
    {
        usage();
        return 1;
    }
    std::string arg{argv[1]};
    if (arg == "-h")
    {
        usage();
        return 1;
    }

    std::size_t wordCount = std::stoull(argv[1]);
    std::multiset<std::string> words;

    scanSet(words, wordCount);

    printSet(words);
    */

    /* Exercise 34
    if (argc < 2)
    {
        usage();
        return 1;
    }

    std::string arg{argv[1]};
    if (arg == "-h")
    {
        usage();
        return 1;
    }

    std::size_t wordCount = std::stoull(argv[1]);
    std::map<std::string, int> words;

    scanMap(words, wordCount);

    printMap(words);
    */

    return 0;
}