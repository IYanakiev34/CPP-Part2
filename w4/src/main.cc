#include "26/base26.h"
#include "26/derived26.h"

Base **derivedFactory(std::size_t size)
{
    Base **bp = new Base *[size];
    for (std::size_t el = 0; el != size; ++el)
        bp[el] = new Derived;

    return bp;
}

void usage()
{
    char const info[] = R"(You must supply the size of the array through the comman line!)";
    std::cout << info << "\n";
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        usage();
        return 0;
    }

    // Allocate the memory
    std::size_t sizeOfArray = atoi(argv[1]);
    Base **bp = derivedFactory(sizeOfArray);

    // Dealocate the memory
    for (std::size_t el = 0; el != 10; ++el)
    {
        delete bp[el];
        std::cout << "Deleted element: " << el << "\n\n";
    }

    delete[] bp;

    return 0;
}