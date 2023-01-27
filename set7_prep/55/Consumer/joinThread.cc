#include "consumer.ih"

void Consumer::joinThread()
{
    if (d_thr.joinable())
        d_thr.join();
}