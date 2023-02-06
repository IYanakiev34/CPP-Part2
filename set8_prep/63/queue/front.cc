#include "BlockQueue.ih"

std::string &BlockingQueue::front()
{
    std::lock_guard<std::mutex> lg(d_mut);

    return d_queue.front();
}