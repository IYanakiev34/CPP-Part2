#include "write_fork.ih"

void WriteFork::parentProcess()
{
    //execl(d_argv[1], d_argv[1], d_argv[2], NULL);
    std::cout << "Failed to execute program\n";
    exit(1);
}