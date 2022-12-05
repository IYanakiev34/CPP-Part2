#include "demo.ih"

Demo::Demo(int x)
{
    try
    {
        throw x;
    }
    catch (int y)
    {
        std::cout << "Thrown value: " << y << "\n";
    }
}