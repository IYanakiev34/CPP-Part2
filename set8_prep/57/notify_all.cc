#include "Semaphore.h"

void Semaphore::notify_all()
{
    std::lock_guard<std::mutex> lg(d_mut);
    if (d_available++ == 0)
        d_cond.notify_all();
}