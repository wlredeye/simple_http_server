#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <unistd.h>
#include <memory>

#include "Worker.h"

class ThreadPool
{
public:
    ThreadPool(int threads, const std::string& dir);
    ~ThreadPool();
    
    // Adds task to a task queue.
    void Enqueue(int socketFd);
    
    // Shut down the pool.
    void ShutDown();

    // Thread pool storage.
    std::vector<std::thread> mThreadPool;
    
    // Queue to keep track of incoming tasks.
    std::queue<int> mTasks;
    
    //Workers container
    std::vector<std::shared_ptr<Worker>> mWorkers;
    
    // Task queue mutex.
    std::mutex tasksMutex;
    
    // Condition variable.
    std::condition_variable condition;
    
    std::string dir;
    // Indicates that pool needs to be shut down.
    bool terminate;
    
    // Indicates that pool has been terminated.
    bool stopped;
    
    // Function that will be invoked by our threads.
    //void Invoke();
};

#endif