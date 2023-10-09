#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>

#define BUFSIZE 30

using namespace std;

void error_handleing(string msg)
{
    cerr<<msg<<endl;
    exit(1);
}

int main(int argc, char *argv[])
{
    int serv_sock;
    char message[BUFSIZE];
    int str_len;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    int clnt_addr_size;

    if(argc != 2)
    {
        cout<<"Useage : " << argv[0] << "<PORT>"<<endl;
        exit(1);  
    }

    serv_sock = socket(PF_INET, SOCK_DGRAM, 0);

    if(serv_sock == -1)
        error_handleing("[Error] socket() : INVALID_SOCKET");
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
        error_handleing("[Error] bind() : SOCKET_ERROR");
    
    while(true)
    {
        clnt_addr_size = sizeof(clnt_addr);
        str_len = recvfrom(serv_sock, message, BUFSIZE, 0, (struct sockaddr*) &clnt_addr, (uint32_t *)&clnt_addr_size);
        sendto(serv_sock, message, str_len, 0, (struct sockaddr*)&clnt_addr, sizeof(clnt_addr));
    }
    
    close(serv_sock);
    return 0;

}
