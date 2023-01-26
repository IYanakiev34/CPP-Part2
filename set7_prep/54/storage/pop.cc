#include "storage.ih"

void Storage::pop()
{
    std::lock_guard<std::mutex> lg(d_mut);
    d_queue.pop();
}