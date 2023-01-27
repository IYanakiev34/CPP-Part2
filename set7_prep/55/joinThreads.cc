#include "main.ih"

void joinThreads(std::vector<Consumer> &threads)
{
    std::for_each(threads.begin(), threads.end(), [](Consumer &thr)
                  { thr.joinThread(); });
}