#include <iostream>
#include <string>

namespace
{
    std::string s_str;
}

std::string *factory(std::string const &str, size_t count)
{
    s_str = str;
    struct StringPlaceholder : public std::string
    {
        StringPlaceholder() : std::string(s_str) {}
    };
    return new StringPlaceholder[count];
}

int main() {
    size_t const count = 2;
    std::string *strings1 = factory("Hello", count);
    std::string *strings2 = factory("World", count);
    for (size_t idx = 0; idx != count; ++idx)
        std::cout << strings1[idx] << '\n' << strings2[idx] << '\n';
    delete[] strings1;
    delete[] strings2;

    /*
     * Output:
     *  Hello
     *  Hello
     *  World
     *  World
     */
}
