#include "main.ih"

int main(int argc, char **argv)
{
    // Ex1
    /*try
    {
        Demo demo{1};
    }
    catch (...)
    {
        std::cerr << "main\n";
    }*/

    /*
    // Ex3
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
    */

    /*
    // Ex 5
    try
    {
        new MaxFour[10];
    }
    catch (std::string const &ex)
    {
        std::cout << ex << "\n";
    }
    */

    // ex 2
    /*
    try
    {
        Arg const &arg = Arg::instance(argc, argv, "ace:fg:h"); // 1

        Process process{arg}; // 2

        process.run(); // 3
    }
    catch (...)
    {
        return handleException();
    }
    */
    return 0;
}