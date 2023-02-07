#ifndef INCLUDED_WRITE_FORK_H_
#define INCLUDED_WRITE_FORK_H_

#include "../fork.h"

class WriteFork : public Fork
{
    int d_argc;
    char **d_argv;
public:
    WriteFork(int argc, char **argv);
private:
    void childProcess() override;
    void parentProcess() override;
    void core() override;
};

inline void WriteFork::core()
{
    fork();
}

#endif