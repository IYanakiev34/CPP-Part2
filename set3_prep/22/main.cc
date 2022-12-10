#include "main.ih"

int main()
{

    // We can call it with derived class
    Derived22 derived;
    caller(derived);

    // We can also call it with base class
    Base22 base;
    caller(base);
    /*
     * We can call it with base class in this case
     * since we do not have any problematic member
     * variables that might have not been intialized
     * and also no function inside the derived class
     * depends on them. However, it is a bad practice
     * and errors could occur (explained in the explain.txt)
     */
    return 0;
}