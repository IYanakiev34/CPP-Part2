#include "CompileWorker.h"

CompileWorker::~CompileWorker()
{
    if (d_thr.joinable())
        d_thr.join();
}
