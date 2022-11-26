#include <iostream>
#include <string>
#include "ex1/demo.h"
#include "ex3/dummy.h"
int main(int argc, char **argv)
{
    /*try
    {
        Demo demo{1};
    }
    catch (...)
    {
        std::cerr << "main\n";
    }*/

    // Throwing without using references
    std::string ivan{"ivan"};
    Dummy dum(ivan);
    try
    {
        throw dum;
    }
    catch (Dummy d)
    {
        std::cout << "Caught\n";
    }

    // Throwing using references
    std::string emo{"emo"};
    Dummy d2{emo};
    try
    {
        throw d2;
    }
    catch (Dummy &dum)
    {
        std::cout << "Caught ref\n";
    }

    return 0;
}