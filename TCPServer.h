#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "ThreadPool.h"

class TCPServer
{
private:
    int mWorkerThreads;
    int mPort;
    std::string mDir;
    std::string mHost;
    
public:
    TCPServer(const std::string &host, int port, const std::string &dir, int threadsCount);
    ~TCPServer(){}
    
    void Run();
};

#endif