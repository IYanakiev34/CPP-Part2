#include <iostream>

char const info[] = R"(Testing compiling with c++ 20)";

int main()
{
    std::cout << info << std::endl;
    return 0;
}