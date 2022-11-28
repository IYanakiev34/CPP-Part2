#include "main.ih"

int main(int argc, char **argv)
{
    try
    {
        Demo demo{1};
    }
    catch (...)
    {
        std::cerr << "main\n";
    }

    return 0;
}
