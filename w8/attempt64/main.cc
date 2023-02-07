#include "write_fork/write_fork.h"

int main(int argc, char **argv)
{
    WriteFork wf{argc, argv};
    wf.execute();
}