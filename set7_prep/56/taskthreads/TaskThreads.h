#ifndef INC_56_TASKTHREADS_H
#define INC_56_TASKTHREADS_H

#include <array>
#include "../task/Task.h"
#include <thread>

class TaskThreads
{
    bool d_isParallel;
    std::array<Task, 4> d_tasks;
    std::array<std::thread, 4> d_threads;
    std::chrono::duration<double> d_timeTaken;

public:
    TaskThreads(int ch, char *argv[]);
    void run();
    void showTime();
    void displayCounts();
};


#endif //INC_56_TASKTHREADS_H
