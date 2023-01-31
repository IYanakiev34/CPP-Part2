#include "semaphore.ih"

void Semaphore::wait()
{
    std::unique_lock<std::mutex> lock(d_mutex);
    d_condition.wait(lock, [this]()
                        { return d_nAvailable > 0; });
    --d_nAvailable;
}