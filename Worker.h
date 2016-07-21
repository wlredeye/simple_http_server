#ifndef WORKER_H
#define WORKER_H

class ThreadPool;

class Worker
{
public:
    Worker(ThreadPool *pool): mPool(pool)
    {
       // enabled = true;
    }
    ~Worker()
    {
       // enabled = false;
       // cv.notify_one();
       // thread.join();
    }
    
    void process();
    
private:
    ThreadPool* mPool;
    
    void handle(int fd);
};

#endif