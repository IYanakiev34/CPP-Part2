#include "main.ih"

int main()
{ // Got rid of the old main, replaced with their template, but can revert
    size_t const size = 10;
    Base **bp = derivedFactory(size);

    // add your code here to return all allocated memory to the common pool.
    for (size_t idx = 0; idx != size; ++idx)
        delete bp[idx];
    delete[] bp;
}