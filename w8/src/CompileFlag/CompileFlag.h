#ifndef COMPILE_FLAG_H
#define COMPILE_FLAG_H

#include <string>

class CompileFlag
{

    unsigned d_threads;
    std::string d_tempDir;
public:
    CompileFlag() = default;
    CompileFlag(unsigned threadNum,std::string const &tempDir = "");

    unsigned getThreadNum() const;
    std::string getTempDir() const;

    void setThreadNum(unsigned const threadNum);
    void setTempDir(std::string const &tempDir);

};

inline unsigned CompileFlag::getThreadNum() const
{
    return d_threads;
}

inline std::string CompileFlag::getTempDir() const
{
    return d_tempDir;
}

inline void CompileFlag::setThreadNum(unsigned const threadNum)
{
    d_threads = threadNum;
}

inline void CompileFlag::setTempDir(std::string const &tempDir)
{
    d_tempDir = tempDir;
}


#endif
