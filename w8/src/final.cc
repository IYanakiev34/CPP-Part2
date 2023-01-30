#include <iostream>
#include <string>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <thread>
#include <unistd.h>   // for fork() and kill()
#include <sys/wait.h> // for waitpid()

class Semaphore
{
public:
    Semaphore(size_t nAvailable) : d_nAvailable(nAvailable) {}

    void wait()
    {
        std::unique_lock<std::mutex> lock(d_mutex);
        d_condition.wait(lock, [this]()
                         { return d_nAvailable > 0; });
        --d_nAvailable;
    }

    void wait_for(size_t seconds)
    {
        std::unique_lock<std::mutex> lock(d_mutex);
        d_condition.wait_for(lock, std::chrono::seconds(seconds), [this]()
                             { return d_nAvailable > 0; });
        --d_nAvailable;
    }

    void set(size_t nAvailable)
    {
        std::unique_lock<std::mutex> lock(d_mutex);
        d_nAvailable = nAvailable;
        d_condition.notify_all();
    }

    std::size_t size() const
    {
        return d_nAvailable;
    }

private:
    std::mutex d_mutex;
    std::condition_variable d_condition;
    size_t d_nAvailable;
};

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <program> <lines> [timeout]\n";
        return 1;
    }

    // Start the child process
    pid_t pid = fork();
    if (pid < 0)
    {
        std::cout << "Failed to fork process\n";
        return 1;
    }

    if (pid == 0)
    {
        // Child process
        // Execute the specified program with the specified arguments
        execl(argv[1], argv[1], argv[2], NULL);
        std::cout << "Failed to execute program\n";
        return 1;
    }
    else
    {
        // Parent process
        Semaphore sem(1);

        // Start a thread to wait for the child process to exit
        std::thread waitThread([&]()
                               {
            int status;
            waitpid(pid, &status, 0);
            sem.set(1); });

        // Wait for the child process to exit or for the timeout to expire
        if (argc == 4)
        {
            sem.wait_for(std::stoul(argv[3]));
            if (sem.size() == 0)
            {
                // Kill the child process if the timeout expired
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
}