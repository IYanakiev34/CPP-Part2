//JB: 0
#include "base26.h"
#include "derived26.h"
#include <iostream>

Base **derivedFactory(std::size_t size) //JB: MF1F
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
        return 0; // JB: Return nonzero on error.
    }

    // Allocate the memory
    std::size_t sizeOfArray = atoi(argv[1]); //JB: 'atoi' is C, not C++. Also: COCO.
    Base **bp = derivedFactory(sizeOfArray);

    // Dealocate the memory
    for (std::size_t el = 0; el != 10; ++el) // JB: Err... what about sizeOfArray?
    {
        delete bp[el];
        std::cout << "Deleted element: " << el << "\n\n";
    }

    delete[] bp;
    return 0;
} //JB: LONG/MLR
/* JB:
   When the user supplies no command line arguments, your program handles the
   situation well by providing usage info. Still it should return a nonzero
   exit code, because from the perspective of the user, it has failed: the
   user expected it to do some job, but instead it showed usage info. (If the
   user had instead specified '-h', then they were requesting usage info. In
   that case, returning 0 after providing the info is right.

   Although I won't subtract points for it, main() is a bit lopsided: on one
   hand, a factory function to allocate memory; on the other hand a loop to
   free it up again.
 */
