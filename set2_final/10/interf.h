#ifndef INTERFACES_H
#define INTERFACES_H
class Arg
{
public:
    static Arg const &instance(unsigned argc, char **argv,
                               char const *arguments);
};

class Process
{
public:
    Process(Arg const &arg);
    void run();
};

#endif