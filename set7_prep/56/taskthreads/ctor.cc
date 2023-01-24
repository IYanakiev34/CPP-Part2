#include "TaskThreads.ih"

TaskThreads::TaskThreads(int argc, char **argv)
        : d_isParallel(argc > 2)
        , d_tasks{
                Task(isVowel, "vowels"),
                Task([](char ch) { return std::isdigit(ch) != 0; }, "digits"),
                Task(isHexadecimal, "hexadecimals"),
                Task(isPunctuation, "punctuation")
        }
        , d_threads{std::array<std::thread, 4>()}
        , d_timeTaken(std::chrono::duration<double>())
{
    for (auto &task : d_tasks)
        task.setTargetFile(argv[1]);
}