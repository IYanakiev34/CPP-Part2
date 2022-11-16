#include "numbers/inc/numbers.h"
#include <iostream>
char const info[] = R"(Testing compiling with c++ 20)";

int main()
{
    std::cout << info << std::endl;
    Numbers nums(10, 10);

    std::cout << nums << std::endl;
    return 0;
}