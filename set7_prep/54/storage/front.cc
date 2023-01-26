#include "storage.ih"

std::string &Storage::front()
{
    std::lock_guard<std::mutex> lg(d_mut);

    return d_queue.front();
}