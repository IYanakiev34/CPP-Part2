#include "main.ih"

int main(int argc, char **argv)
{
    // Ex 18
    std::cout << "BASE CONSTRUCTION\n";
    // Base constructors
    Derived normal{};
    std::cout << "\n\n";

    std::cout << "COPY CONSTRUCTION\n";
    // Copy construction
    Derived copy{normal};
    std::cout << "\n\n";

    std::cout << "MOVE CONSTRUCTION\n";
    // Move construction
    Derived move{std::move(copy)};
    std::cout << "\n\n";

    std::cout << "DESTRUCTION TAKES PLACE NOW\n";

    return 0;
}