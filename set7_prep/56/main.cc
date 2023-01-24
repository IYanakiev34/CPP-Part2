#include "taskthreads/TaskThreads.h"

int main(int argc, char **argv)
{
    TaskThreads taskThreads(argc, argv);
    taskThreads.run();
    taskThreads.displayCounts();
    taskThreads.showTime();
}