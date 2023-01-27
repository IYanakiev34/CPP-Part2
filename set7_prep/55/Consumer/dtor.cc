#include "consumer.ih"

Consumer::~Consumer()
{
    if (d_thr.joinable())
        d_thr.join();
}