#include "storage.ih"

void Storage::push(std::string const &line)
{
    std::lock_guard<std::mutex> lg(d_mut);
    d_queue.push(line);
}