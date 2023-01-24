#include "Task.ih"

void Task::operator()()
{
    std::ifstream file(d_targetFile);
    char c;
    while (file.get(c))
        if (d_charPredicate(c))
            ++d_count;
}
