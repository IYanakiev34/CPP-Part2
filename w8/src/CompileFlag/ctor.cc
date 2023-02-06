#include "CompileFlag.h"

CompileFlag::CompileFlag(unsigned threadNum,std::string const &tempDir)
    : d_tempDir(tempDir)
{
    if (threadNum == 0)
        d_threads = 1;
    else
        d_threads = threadNum;
}
