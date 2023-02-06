#include "BlockQueue.ih"

void BlockingQueue::push(std::string const &item)
{
    std::lock_guard<std::mutex> lg(d_mut);
    d_queue.push(item);
}