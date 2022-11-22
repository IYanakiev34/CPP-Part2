#include "msg.ih"

void show(Msg msg)
{
    std::bitset<8> bits(static_cast<int>(msg));

    if (bits.count() == 0)
    {
        std::cout << "NONE\n";
        return;
    }

    if (bits.count() == bits.size())
    {
        std::cout << "ALL\n";
        return;
    }

    char const *names[] = {"DEBUG", "INFO", "NOTICE", "WARNING", "ERR", "CRIT", "ALERT", "EMERG"};
    int const len = sizeof(names) / sizeof(names[0]);

    for (std::size_t i = 0; i != bits.size(); ++i)
    {
        if (bits.test(i))
            std::cout << names[i] << ' ';
    }
    std::cout << "\n";
}