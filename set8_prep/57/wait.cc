#include "Semaphore.h"

void Semaphore::wait()
{

    std::unique_lock<std::mutex> ul(d_mut);
    while (d_available == 0)
        d_cond.wait(ul);

    --d_available;
}