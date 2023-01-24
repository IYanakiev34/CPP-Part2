#ifndef INC_56_TASK_H
#define INC_56_TASK_H

#include <string>

class Task
{
    size_t d_count;
    bool (*d_charPredicate)(char);
    std::string d_label;
    std::string d_targetFile;

public:
    Task(bool (*charPredicate)(char), std::string label);
    void operator()();
    [[nodiscard]] size_t count() const;
    [[nodiscard]] std::string label() const;
    void setTargetFile(std::string const &targetFile);
};

inline size_t Task::count() const
{
    return d_count;
}

inline std::string Task::label() const
{
    return d_label;
}

inline void Task::setTargetFile(std::string const &targetFile)
{
    d_targetFile = targetFile;
}

#endif //INC_56_TASK_H
