#ifndef FORK_INCLUDED_H
#define FORK_INCLUDED_H

#include <sys/types.h>
#include <iosfwd>

class Fork
{
    pid_t d_pid;

public:
    virtual ~Fork();

    void fork();

protected:
    virtual void parentProcess() = 0;
    virtual void childProcess() = 0;

    pid_t pid() const;
    int waitForChild() const;
};

inline pid_t Fork::pid() const
{
    return d_pid;
}

#endif