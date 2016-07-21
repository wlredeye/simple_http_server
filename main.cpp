#include <iostream>
#include <iostream>
#include <signal.h>
#include <unistd.h>

#include "TCPServer.h"

int main(int argc, char **argv) {
    daemon(1, 1);
    
    std::string host;
    int port = 8080;
    std::string dir;
    
    int opt = getopt( argc, argv, "h:p:d:");
    while( opt != -1 ) {
        switch( opt ) {
            case 'h':
                host=optarg;
                break;
                
            case 'p':
                port = atoi(optarg);
                break;
                
            case 'd':
                dir = optarg;
                break;
        }
        
        opt = getopt( argc, argv, "h:p:d:");
    }
    TCPServer* tcpsrv = new TCPServer(host, port, dir, 8);
    
    tcpsrv->Run();
    
    return 0;
}
