#include <iostream>
#include "Derived.h"
#include "Derived2.h"

int main()
{
    std::cout << "Basic derived implementation\n\n";

    std::cout << "Default constructor\n";
    Derived d1;
    std::cout << "\n";

    std::cout << "Copy constructor\n";
    [[maybe_unused]] Derived d2(d1);
    std::cout << "\n";

    std::cout << "Move constructor\n";
    [[maybe_unused]] Derived d3((std::move(d1)));
    std::cout << "\n";

    std::cout << "Modified derived implementation\n";

    std::cout << "Default constructor\n";
    Derived2 d4;
    std::cout << "\n";

    std::cout << "Copy constructor\n";
    [[maybe_unused]] Derived2 d5(d4);
    std::cout << "\n";

    std::cout << "Move constructor\n";
    [[maybe_unused]] Derived2 d6(std::move(d4));
    std::cout << "\n";
}
