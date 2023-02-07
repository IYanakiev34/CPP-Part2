#ifndef INCLUDED_WRITE_FORK_H_
#define INCLUDED_WRITE_FORK_H_

#include "../fork.h"

class WriteFork : public Fork
{
    int d_argc;
    char **d_argv;
public:
    WriteFork(int argc, char **argv)
        : d_argc(argc)
        , d_argv(argv)
    {}
private:
    void childProcess() override;
    void parentProcess() override;
    void core() override
    {
        fork();
        waitForChild();
    }
};

#endif