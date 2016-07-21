#include "ThreadPool.h"

// Constructor.
ThreadPool::ThreadPool(int threads, const std::string& d) :
dir(d),
terminate(false),
stopped(false)
{
    // Create number of required threads and add them to the thread pool vector.
    for(int i = 0; i < threads; i++)
    {
        std::shared_ptr<Worker> worker(new Worker(this));
        mWorkers.push_back(worker);
        mThreadPool.emplace_back(std::thread(&Worker::process, worker));
    }
}

void ThreadPool::Enqueue(int socketFd)
{
    // Scope based locking.
    {
        // Put unique lock on task mutex.
        std::unique_lock<std::mutex> lock(tasksMutex);
        
        // Push task into queue.
        mTasks.push(socketFd);
    }
    
    // Wake up one thread.
    condition.notify_one();
}

void ThreadPool::ShutDown()
{
    // Scope based locking.
    {
        // Put unique lock on task mutex.
        std::unique_lock<std::mutex> lock(tasksMutex);
        
        // Set termination flag to true.
        terminate = true;
    }
    
    // Wake up all threads.
    condition.notify_all();
    
    // Join all threads.
    for(std::thread &thread : mThreadPool)
    {
        thread.join();
    }
    
    // Empty workers vector.
    mThreadPool.empty();
    
    // Indicate that the pool has been shut down.
    stopped = true;
}

ThreadPool::~ThreadPool()
{
    if (!stopped)
    {
        ShutDown();
    }
}