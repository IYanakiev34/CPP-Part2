#include "main.ih"

void usage()
{
    char const info[] = R"(Please specify the amount of words you wish to enter!)";
    std::cout << info << "\n";
}

int main(int argc, char **argv)
{
    if (argc < 2 || (argc == 2 && argv[1] == "-h"))
    {
        usage();
        return 1;
    }

    std::size_t const wordCount = std::stoull(argv[1]);
    std::map<std::string, int> words;

    scanMap(words, wordCount, std::cin);

    printMap(words, std::cout);
}
