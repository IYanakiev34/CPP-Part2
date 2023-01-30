#include "consumer.ih"

Consumer::~Consumer()
{
    if (d_thr.joinable())
        d_thr.join();

    // No need to delete Storage pointer since it is non-owning pointer
}