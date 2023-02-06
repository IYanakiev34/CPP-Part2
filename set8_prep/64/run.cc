#include "main.ih"

void run(pid_t pid, int argc, char **argv)
{
    Semaphore sem(1);
    std::thread waitThread([&]()
    {
        int status;
        waitpid(pid, &status, 0);
        sem.set(1); 
    });

    if (argc == 4)
    {
        sem.wait_for(std::stoul(argv[3]));
        if (sem.size() == 0)
        {
            kill(pid, SIGKILL);
            std::cout << "Program ended at timeout\n";
        }
        else
        {
            std::cout << "Program ended normally\n";
        }
    }
    else
    {
        sem.wait();
        std::cout << "Program ended normally\n";
    }    
}