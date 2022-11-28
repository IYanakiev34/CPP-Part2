#include "main.ih"

int main()
{
    try
    {
        new MaxFour[10];
    }
    catch (std::string const &ex)
    {
        std::cout << ex << "\n";
    }
    return 0;
}