#include "Worker.h"
#include "ThreadPool.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <streambuf>

void Worker::process(){
    int socketFd;
    while(true)
    {
        // Scope based locking.
        {
            // Put unique lock on task mutex.
            std::unique_lock<std::mutex> lock(mPool->tasksMutex);
            
            // Wait until queue is not empty or termination signal is sent.
            mPool->condition.wait(lock, [this]{ return !mPool->mTasks.empty() || mPool->terminate; });
            
            // If termination signal received and queue is empty then exit else continue clearing the queue.
            if (mPool->terminate && mPool->mTasks.empty())
            {
                return;
            }
            
            // Get next task in the queue.
            socketFd = mPool->mTasks.front();
            
            // Remove it from the queue.
            mPool->mTasks.pop();
        }
        std::cout << "take in work";
        // Execute the task.
        handle(socketFd);
    }
}

void Worker::handle(int fd) {
    int count;
    char data;
    
    std::string buf;
    std::string path;
    bool is_path = false;
    
    while((count = recv(fd, &data, 1, MSG_NOSIGNAL)) > 0){
        buf.append(&data, 1);

        if(data == ' '){
            if(buf == "GET "){
                is_path = true;

                std::cout << buf;
                flush(std::cout);
                buf.clear();
                continue;
            }
            if(is_path){
                buf.erase(buf.size() - 1, buf.size());
                std::cout << buf;
                flush(std::cout);
                path = buf;
                //buf.clear();
                is_path = false;
            }
        } else {
            if(data  == '\n') {
                int nbytes = buf.size();
                if(nbytes >=4 && buf[nbytes-1] == '\n' && buf[nbytes-2] == '\r'
                   && buf[nbytes-3] == '\n' && buf[nbytes-4] == '\r'){
                    
                    std::cout << buf;
                    flush(std::cout);
                    
                    size_t pos = path.find('?');
                    if (pos != std::string::npos) {
                        path = std::string(path.data(), pos);
                    }
                    path = mPool->dir + path;
                    std::ifstream file(path, std::ios::binary);
                    
                    std::stringstream ss;
                    if(file.good()){
                        //size_t fsize = file.tellg();
                       // file.seekg (0, std::ios::beg);
                        
                        //std::string str((std::istreambuf_iterator<char>(file)),
                        //                std::istreambuf_iterator<char>());
                 
                        ss << "HTTP/1.0 200 OK\r\n";
                        ss << "Content-Type: text/html\r\n";
                       // ss << "Content-Length: " << fsize  << "\r\n" << "\r\n";
                        ss << "Connection: close\r\n\r\n";
                        
                        int r = send(fd, ss.str().data(), ss.str().size(),MSG_NOSIGNAL);
                        if(r == -1){
                            shutdown(fd, SHUT_RDWR);
                            close(fd);
                            file.close();
                            return;
                        }
                        char chunkToRead[1024];
                        size_t chunkSize = sizeof(chunkToRead);
                        file.read(chunkToRead, chunkSize);
                        while(file.gcount() > 0) {
                            r = send(fd, chunkToRead, file.gcount(), MSG_NOSIGNAL);
                            if(r == - 1){
                                break;
                            }
                            file.read(chunkToRead, chunkSize);
                        }
                        
                    } else {
                        ss << "HTTP/1.0 404 Not Found\r\n";
                        ss << "Content-Length: 0\r\n";
                        ss << "Content-Type: text/html\r\n\r\n";
                        send(fd, ss.str().data(), ss.str().size(),MSG_NOSIGNAL);
                    }
                    
                    shutdown(fd, SHUT_RDWR);
                    close(fd);
                    file.close();
                    return;
                }
            }
        }
    }
    
}