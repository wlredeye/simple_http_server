#include "TCPServer.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>

#include <sys/epoll.h>
#include <arpa/inet.h>

#define MAX_EVENTS 32

int set_nonblock(int fd){
    int flags;
#if defined(O_NONBLOCK)
    if(-1 == (flags = fcntl(fd, F_GETFL, 0)))
        flags = 0;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    flags = 1;
    return ioctl(fd, FIOBIO, &flags);
#endif
}

TCPServer::TCPServer(const std::string &host, int port, const std::string &dir,
                     int threadsNum): mPort(port), mDir(dir), mWorkerThreads(threadsNum){
}

void TCPServer::Run()
{
    ThreadPool pool(mWorkerThreads, mDir);
    
    int MasterSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_port = htons(mPort);
    inet_pton(AF_INET, mHost.c_str(), &SockAddr.sin_addr);
    
    SockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(MasterSocket, (struct sockaddr*)(&SockAddr), sizeof(SockAddr));
    
    set_nonblock(MasterSocket);
    listen(MasterSocket,SOMAXCONN);
    
    int Epoll = epoll_create1(0);
    
    struct epoll_event Event;
    Event.data.fd = MasterSocket;
    Event.events = EPOLLIN; //which events we should receive. EPOLLIN - read events
    epoll_ctl(Epoll, EPOLL_CTL_ADD, MasterSocket, &Event);
    
    while(true){
        struct epoll_event Events[MAX_EVENTS];
        int N = epoll_wait(Epoll, Events, MAX_EVENTS, -1);
        if (N < 0 && errno == EINTR) {
            continue;
        }

        for(unsigned int i = 0; i < N; i++){
            int currentFd = Events[i].data.fd;
            if(Events[i].data.fd == MasterSocket){
                int SlaveSocket = accept(MasterSocket, 0, 0);
                set_nonblock(SlaveSocket);
                pool.Enqueue(SlaveSocket);
            }
        }
    }
    
}