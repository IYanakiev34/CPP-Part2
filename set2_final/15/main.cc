#include "main.ih"

void leaking()
{
    std::string leak{"We will leak!"};
    Dummy dum{leak};
    exit(3); // Exit does not call destructors so we leak
}

void noLeak()
{
    std::string noLeak{"We won't leak\n"};
    try
    {
        Dummy dum{noLeak};
    }
    catch (...)
    {
        std::cout << "ex caught\n"; // Destructor will be called for dum
    }
}

int main()
{
    noLeak(); // Call no leak first so that exit does not stop this function

    leaking(); // Show that the function leaks
    return 0;
}