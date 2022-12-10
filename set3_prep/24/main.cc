#include "main.ih"

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
     *  World
     *  Hello
     *  World
     */
}