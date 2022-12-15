#include "main.ih"

void usage()
{
    char const info[] = R"(Please specify the amount of words you wish to enter!)";
    std::cout << info << "\n";
}

int main(int argc, char **argv)
{
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
    return 0;
}