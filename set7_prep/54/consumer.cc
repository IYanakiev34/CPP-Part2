#include "main.ih"

void consumer(Storage &str, std::ostream &out)
{
    while (!str.getFinished())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (!str.empty())
        {
            out << str.front() << "\n";
            str.pop();
        }
    }
}