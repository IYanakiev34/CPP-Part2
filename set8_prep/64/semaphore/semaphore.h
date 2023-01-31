#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>

class Semaphore
{
    std::mutex d_mutex;
    std::condition_variable d_condition;
    size_t d_nAvailable;
public:
    Semaphore(size_t nAvailable) : d_nAvailable(nAvailable) {}
    void wait();
    void wait_for(size_t seconds);
    void set(size_t nAvailable);
    std::size_t size() const;
};

inline size_t Semaphore::size() const
{
    return d_nAvailable;
}

#endif