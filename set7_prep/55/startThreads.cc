#include "main.ih"

void startThreads(std::vector<Consumer> &threads)
{
    std::for_each(threads.begin(), threads.end(), [](Consumer &thr)
                  { thr.startThread(); });
}