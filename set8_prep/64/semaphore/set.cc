#include "semaphore.ih"

void Semaphore::set(size_t nAvailable)
{
    std::unique_lock<std::mutex> lock(d_mutex);
    d_nAvailable = nAvailable;
    d_condition.notify_all();
}