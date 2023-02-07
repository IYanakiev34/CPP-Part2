#ifndef INCLUDED_FORK_H_
#define INCLUDED_FORK_H_

class Fork
{
    int d_pid;

    public:
        Fork() = default;
        Fork(Fork const &other) = delete;
        virtual ~Fork();

        void fork();
        Fork *clone() const;

        void execute();

    protected:
        int pid() const;
        int waitForChild() const; // returns the status

    private:
        virtual void childProcess() = 0;    // pure virtual member
        virtual void parentProcess() = 0;
        virtual Fork *copy() const;         // throws if called
        virtual void core();                // no Fork actions
};

inline int Fork::pid() const
{
    return d_pid;
}

inline Fork *Fork::clone() const
{
    return copy();
}

inline void Fork::execute()
{
    core();
}

inline void Fork::core()
{}

#endif