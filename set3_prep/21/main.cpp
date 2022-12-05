#include <iostream>
#include "String.h"

inline String bool_to_string(bool b)
{
    return String{b ? "true" : "false"};
}

int main()
{
    String str{"Helloworld!"};
    std::cout << "Before inserting a space at position 5: " << str << "\n";
    str.std::string::insert(5, 1, ' ');
    std::cout << "After insert: " << str << "\n\n";
    std::cout << "Demonstrating comparisons:\n";
    std::cout << "str == str: " << bool_to_string(str == str) << "\n";
    std::cout << "str != str: " << bool_to_string(str != str) << "\n";
    std::cout << "str < str: " << bool_to_string(str < str) << "\n";
    std::cout << "str <= str: " << bool_to_string(str <= str) << "\n";
    std::cout << "str > str: " << bool_to_string(str > str) << "\n";
    std::cout << "str >= str: " << bool_to_string(str >= str) << "\n";
}
