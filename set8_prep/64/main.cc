#include "main.ih"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <program> <lines> [timeout]\n";
        return 1;
    }

    pid_t pid = fork();
    if (pid <= 0) 
    {
        if (pid == 0) 
        {
            execl(argv[1], argv[1], argv[2], NULL);
            std::cout << "Failed to execute program\n";
            return 1;
        }
        std::cout << "Failed to fork process\n";
        return 1;
    }
    else
        run(pid, argc, argv);
}