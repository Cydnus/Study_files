#include <iostream>
#include <vector>
#include <winsock2.h>

#define BUF_SIZE    1024


using namespace std;

void ErrorHandling(string str)
{
    cerr<<str<<endl;
    exit(1);
}

int main(int argc, char** argv)
{
    WSADATA wsaData;
    
    SOCKET hServerSock;
    SOCKET hClientSock;
    
    char message[BUF_SIZE];
    int strLen;

    SOCKADDR_IN servAddr;
    SOCKADDR_IN clntAddr;
    int clntAddrSize;
    
    if(argc!=2)
    {
        cout<<"Useage : "<<argv[0]<<" <PORT>"<<endl;
        exit(1);
    }

    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
        ErrorHandling("[Error] WSAStartup()");

    hServerSock = socket(PF_INET, SOCK_STREAM, 0);
    if(hServerSock == INVALID_SOCKET)
        ErrorHandling("[Error] socket() : INVALID_SOCKET");
    
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi(argv[1]));

    if(bind(hServerSock, (SOCKADDR *) &servAddr, sizeof(servAddr)) == SOCKET_ERROR)
        ErrorHandling("[Error] bind() : SOCKET_ERROR");

    if(listen(hServerSock, 5) == SOCKET_ERROR)
        ErrorHandling("[Error] listen() : SOCKET_ERROR");
    
    clntAddrSize = sizeof(clntAddr);
    while(true)
    {
        hClientSock = accept(hServerSock, (SOCKADDR *) &clntAddr, &clntAddrSize);
        if(hClientSock == INVALID_SOCKET)
            ErrorHandling("[Error] accept() : INVALID_SOCKET");

        if( (strLen = recv(hClientSock, message, BUF_SIZE-1, 0)) != 0){
            message[strLen] = 0;
            cout<<"From Client : "<<message<<endl;
            send(hClientSock, message, strLen, 0);
        }

        closesocket(hClientSock);
    }


    WSACleanup();
    return 0;
}