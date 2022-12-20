#ifndef FORK_INCLUDED_H
#define FORK_INCLUDED_H

#include <sys/types.h>
#include <iosfwd>

/* JB:
   What does it even mean to copy a Fork object?

   Alex:
   Disabled move and copy ctor and assign with =delete
 */

class Fork
{
    pid_t d_pid;

public:
    virtual ~Fork(); //JB: :-)

    void fork();

    Fork(Fork const &other) = delete;
    Fork(Fork &&other) = delete;
    Fork &operator=(Fork const &other) = delete;
    Fork &operator=(Fork &&other) = delete;

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
