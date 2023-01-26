#include "storage.h"

bool Storage::empty()
{
    std::lock_guard<std::mutex> lg(d_mut);
    return d_queue.empty();
}