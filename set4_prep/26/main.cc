#include "main.ih"

void usage()
{
    const char info[] = R"(
        The program must be supplied with integer value
        representing how many derived objects you want
        the factory to produce.)";

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

    // Allocate memory
    std::size_t sizeOfArray = std::stoull(argv[1]);
    Base **bp = derivedFactory(sizeOfArray);

    // Free memory
    freeBasePointers(bp, sizeOfArray);

    return 0;
}