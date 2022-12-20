#include "fork.ih"

void Fork::fork()
{
    d_pid = ::fork();

    if (d_pid == 0)
        childProcess();
    else
        parentProcess();
}
