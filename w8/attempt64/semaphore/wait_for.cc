#include "semaphore.ih"
#include <iostream>

void Semaphore::wait_for(size_t seconds)
{
    std::unique_lock<std::mutex> lock(d_mutex);
    d_condition.wait_for(lock, std::chrono::seconds(seconds), [this]()
                            { return d_nAvailable > 0; });
    --d_nAvailable;
}