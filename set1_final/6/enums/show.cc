#include "msg.ih"

char const *names[] = {"DEBUG", "INFO", "NOTICE",
                       "WARNING", "ERR", "CRIT", "ALERT", "EMERG"};
void show(Msg msg)
{
    int int_msg = static_cast<int>(msg);
    if (int_msg == 0)
    {
        std::cout << "NONE\n";
        return;
    }

    for (std::size_t idx = 0; idx != 8; ++idx)
    {
        if (int_msg & (1 << idx))
            std::cout << names[idx] << ' ';
    }

    std::cout << '\n';
}