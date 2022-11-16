#include <iostream>
#include "numbers/include/numbers.h"

char const info[] = R"(Testing compiling with c++ 20)";

int main()
{
    std::cout << info << std::endl;
    Numbers num(10);
    std::cout << "Printing the numbers ...\n";
    std::cout << num << std::endl;
    return 0;
}