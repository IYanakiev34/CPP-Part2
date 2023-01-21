#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main(int argc, char **argv)
{
    std::sort(argv + 1, argv + argc, std::less<std::string>());
    std::copy(argv + 1, argv + argc,
              std::ostream_iterator<char const *>(std::cout, " "));
    std::cout << '\n';

    std::sort(argv + 1, argv + argc, std::greater<std::string>());
    std::copy(argv + 1, argv + argc,
              std::ostream_iterator<char const *>(std::cout, " "));
    std::cout << '\n';
}