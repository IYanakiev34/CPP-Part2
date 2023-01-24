#include "multiout.ih"

void MultiOut::run()
{
    std::vector<std::thread> threads;
    for (size_t idx = 0; idx != d_numThreads; ++idx)
        threads.emplace_back(display, idx);
    for (auto &thread: threads)
        thread.join();
}