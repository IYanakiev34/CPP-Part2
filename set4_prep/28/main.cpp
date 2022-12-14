#include "main.ih"

int main()
{
    RandBuffer randBuffer{1, 1000, 2};
    for (size_t idx = 0; idx != 10; ++idx)
        std::cout << randBuffer.sbumpc();
    std::cout << '\n';
}
