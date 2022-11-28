#include <iostream>
#include <string>

// Uncomment and try to compile to observe the issue
/*
bool promptNotCompile(std::istream &in, std::string &str)
{
    std::cout << "Enter something\n";

    return getline(in, str);
}*/

bool promptCompilesBodyChange(std::istream &in, std::string &str)
{
    std::cout << "Enter something\n";

    return static_cast<bool>(getline(in, str));
}

std::istream &promptCompilesReturnChange(std::istream &in, std::string &str)
{
    std::cout << "Enter something\n";

    return getline(in, str);
}

int main()
{
    std::cout << "Starting program...\n";

    // you could test the function here for example
    std::string str{""};
    while (promptCompilesBodyChange(std::cin, str))
        std::cout << "string is: " << str << std::endl;
}
