#include "BlockQueue.ih"

bool BlockingQueue::empty()
{
    std::lock_guard<std::mutex> lg(d_mut);
    return d_queue.empty();
}