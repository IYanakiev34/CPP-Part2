#include "main.ih"

int main(int agrc, char **argv)
{
    IotaWrapper wrap(0, [](unsigned const &n)
                     { return n + 2; });
    std::vector<unsigned> data(10);
    std::iota(data.begin(), data.end(), wrap);
    std::copy(data.begin(), data.end(), std::ostream_iterator<unsigned>(std::cout, " "));
    std::cout << std::endl;
}