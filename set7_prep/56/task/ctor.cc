#include "Task.ih"

Task::Task(bool (*charPredicate)(char), std::string label)
        : d_count(0)
        , d_charPredicate(charPredicate)
        , d_label(std::move(label))
{
}