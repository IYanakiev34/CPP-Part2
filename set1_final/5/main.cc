#include "main.ih"

void fun(First::Enum t)
{
    std::cout << "Called from main function\n";
}

int main()
{
    // fun(First::Enum{}) produces error due to ambiguity

    // fun in main is commmented then
    // fun(First::Enum{}) will call the fun function in the First namespace
    // Second::fun(First::Enum{}) used to call fun in the Second namespace
}
