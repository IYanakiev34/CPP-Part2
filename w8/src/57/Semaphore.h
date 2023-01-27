#ifndef SEMAPHORE_H
#define SEMAPHONE_H

#include <mutex>
#include <condition_variable>

class Semaphore
{
    std::size_t d_available;
    std::mutex d_mut;
    std::condition_variable d_cond;

public:
    Semaphore(std::size_t available);

    void notify();
    void notify_all();

    std::size_t size() const;

    void wait();
};

inline std::size_t Semaphore::size() const
{
    return d_available;
}

#endif