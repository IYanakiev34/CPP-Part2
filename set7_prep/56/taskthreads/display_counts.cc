#include "TaskThreads.ih"

void TaskThreads::displayCounts()
{
    for (auto &task : d_tasks)
        std::cout << task.label() << ": " << task.count() << '\n';
}
