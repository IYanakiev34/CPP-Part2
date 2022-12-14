#include "fork.ih"

void Fork::fork()
{
    if ((d_pid = ::fork()) < 0)
        throw "Fork method fork\n";
        //JB: I don't understand that message. But -0

    if (d_pid == 0)
    {
        childProcess();

        throw 1; //JB: I don't understand that at all.
    }

    parentProcess();
}
