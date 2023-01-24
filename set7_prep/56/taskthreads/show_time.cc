#include "TaskThreads.ih"

void TaskThreads::showTime()
{
    std::cout << "Time taken: " << d_timeTaken.count() << " seconds" << '\n';
}