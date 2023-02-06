#include "CompileWorker.h"

void CompileWorker::startWorker()
{
    d_thr = std::thread(&CompileWorker::compileJob,std::ref(*this),std::ref(*d_jobQueue)
            ,std::ref(*d_mut),std::ref(*d_sem));
}
