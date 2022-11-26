#include "../inc/msg.ih"

char const *names[] = {"DEBUG", "INFO", "NOTICE",
                       "WARNING", "ERR", "CRIT", "ALERT", "EMERG"};
void show(Msg msg)
{
    // Handle case when NONE
    if (static_cast<int>(msg) == 0)
    {
        std::cout << "NONE\n";
        return;
    }

    // Handle case where all
    if (static_cast<int>(msg) == 255)
    {
        std::cout << "ALL\n";
        return;
    }

    Msg const msgs[] = {Msg::DEBUG, Msg::INFO, Msg::NOTICE,
                        Msg::WARNING, Msg::ERR, Msg::CRIT, Msg::ALERT, Msg::EMERG};

    int const len = sizeof(names) / sizeof(names[0]);

    // Iterate over each Msg type and check if bit is set
    for (std::size_t name = 0; name != len; ++name)
    {
        if (static_cast<int>(msg & msgs[name]) > 0)
            std::cout << names[name] << ' ';
    }
    std::cout << "\n";
}