#include "main.ih"

int main()
{
    std::string from{"main.cc"};
    std::string to{"main.copy"};
    copyFile(from, to);

    return 0;
}