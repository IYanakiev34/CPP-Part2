#include "fork.h"
#include <unistd.h>
#include <stdexcept>
#include <sys/wait.h>

Fork::~Fork()
{}

void Fork::fork()
{
    if ((d_pid = ::fork()) < 0)
        throw "Fork::fork() failed";

    if (d_pid == 0)                 // childprocess has pid == 0
    {
        childProcess();
        throw "Fork::fork(): child process didn't exit";
    }                               // childProcess() must exit
    parentProcess();
}

Fork *Fork::copy() const
{
    throw "Cannot copy Fork";
}