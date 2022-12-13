#include "fork.ih"

void Fork::fork()
{
    if ((d_pid = ::fork()) < 0)
        throw "Fork method fork\n";

    if (d_pid == 0)
    {
        childProcess();

        throw 1;
    }

    parentProcess();
}