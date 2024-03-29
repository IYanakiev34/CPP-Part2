#include "write_fork.ih"

void WriteFork::parentProcess()
{
    Semaphore sem(1);
    std::thread waitThread([&]()
    {
        int status;
        waitpid(pid(), &status, 0);
        sem.set(1); 
    });
    waitThread.detach();

    if (d_argc == 4)
    {
        if (sem.size() == 0)
        {
            kill(pid(), SIGKILL);
            std::cout << "Program ended at timeout\n";
        }
        else
            std::cout << "Program ended normally\n";
    }
    else
    {
        sem.wait();
        std::cout << "Program ended normally\n";
    }
}