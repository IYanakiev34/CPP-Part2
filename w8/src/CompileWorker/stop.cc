#include "CompileWorker.h"

void CompileWorker::stopWorker()
{
    if (d_thr.joinable())
        d_thr.join();
}
