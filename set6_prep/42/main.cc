#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main(int argc, char **argv)
{
    // Exercise 42
    std::sort(argv + 1, argv + argc, [](auto l, auto r)
              { return std::stoi(l) < std::stoi(r); });
    std::copy(argv + 1, argv + argc, std::ostream_iterator<char const *>(std::cout, " "));
    std::cout << "\n";

    std::sort(argv + 1, argv + argc, [](auto l, auto r)
              { return std::stoi(l) > std::stoi(r); });
    std::copy(argv + 1, argv + argc, std::ostream_iterator<char const *>(std::cout, " "));
    std::cout << std::endl;
}