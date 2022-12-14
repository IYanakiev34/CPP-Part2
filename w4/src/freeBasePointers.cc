#include "main.ih"

void freeBasePointers(Base **bp, std::size_t size)
{
    // Dealocate the memory
    for (std::size_t el = 0; el != size; ++el)
    {
        delete bp[el];
        std::cout << "Deleted element: " << el << "\n\n";
    }

    delete[] bp;
}