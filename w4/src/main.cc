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
    /*
    // Exercise 26
    if (argc < 2)
    {
        usage();
        return 1;
    }

    // Allocate memory
    std::size_t sizeOfArray = std::stoull(argv[1]);
    Base **bp = derivedFactory(sizeOfArray);

    // Free memory
    freeBasePointers(bp, sizeOfArray);
    */

    std::ofstream one("one");
    std::ofstream two("two");

    BiStream biStream(one, two);

    biStream << "Hello world!" << std::endl;

    return 0;
}