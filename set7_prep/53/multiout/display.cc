#include "multiout.ih"

void display(size_t threadId)
{
    std::stringstream ss;
    for (size_t idx = 0; idx != 4; ++idx)
    {
        std::cout << "thread " << threadId << '\n';
        ss << "Line " << idx << " from thread " << threadId << '\n';
        std::this_thread::yield();
    }
    std::cout << ss.str();
}