#include <iostream>
#include <string>
#include "StringRepeat.h"

void printStringValue(std::string const &str)
{
    std::cout << "Printing string value\n";
    std::cout << str << "\n\n";
}

void printStringReference(std::string const &str)
{
    std::cout << "Printing string reference\n";
    std::cout << str << "\n\n";
}

void printStringRValueReference(std::string &&str)
{
    std::cout << "Printing string rvalue reference\n";
    std::cout << str << "\n\n";
}

void printStringPointer(std::string const *str)
{
    std::cout << "Printing string pointer\n";
    std::cout << *str << "\n\n";
}

int main()
{
    /*
     * Show StringRepeat used as argument in place of string as:
     * - value
     * - reference
     * - rvalue reference
     * - pointer to string
     */
    StringRepeat strRepeat(3, "Hello ");
    printStringValue(strRepeat);
    printStringReference(strRepeat);
    printStringRValueReference(StringRepeat{3, "Hello "});
    printStringPointer(&strRepeat);
}
