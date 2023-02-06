#include "CompileWorker.h"

CompileWorker::CompileWorker(BlockingQueue &queue,std::mutex &mut,Semaphore &sem)
    : d_mut(&mut),
      d_jobQueue(&queue),
      d_sem(&sem)
{

}
