#include "TaskThreads.ih"

void TaskThreads::run()
{
    auto start = std::chrono::system_clock::now();
    if (d_isParallel)
    {
        for (auto &task : d_tasks)
            task();
    } else {
        for (size_t idx = 0; idx != 4; ++idx)
            d_threads[idx] = std::thread(std::ref(d_tasks[idx]));
        for (auto &thread : d_threads)
            thread.join();
    }
    d_timeTaken = std::chrono::system_clock::now() - start;
}