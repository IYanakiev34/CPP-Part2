#ifndef COMPILE_WORKER_H
#define COMPILE_WORKER_H

#include "../queue/BlockQueue.h"
#include "../57/Semaphore.h"
#include <mutex>
#include <thread>

class CompileWorker
{
    std::mutex *d_mut;
    BlockingQueue *d_jobQueue;
    std::thread d_thr;
    Semaphore *d_sem;
public:
    CompileWorker(BlockingQueue &queue,std::mutex &mut,Semaphore &sem);
    ~CompileWorker();

    void startWorker();
    void stopWorker();
    
private:
    void compileJob(BlockingQueue &queue,std::mutex &mut,Semaphore &sem);

};

#endif
