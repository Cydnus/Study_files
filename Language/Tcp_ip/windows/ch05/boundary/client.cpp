#include <iostream>
#include <vector>
#include <winsock2.h>
#include <windows.h>

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
    
    char message[BUF_SIZE];
    int strLen;

    SOCKADDR_IN servAddr;
    if(argc!=3)
    {
        cout<<"Useage : "<<argv[0]<<" <IP> <PORT>"<<endl;
        exit(1);
    }

    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
        ErrorHandling("[Error] WSAStartup()");

    hServerSock = socket(PF_INET, SOCK_STREAM, 0);
    if(hServerSock == INVALID_SOCKET)
        ErrorHandling("[Error] socket() : INVALID_SOCKET");
    
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(argv[1]);
    servAddr.sin_port = htons(atoi(argv[2]));

    if(connect(hServerSock, (SOCKADDR *) &servAddr, sizeof(servAddr)) == SOCKET_ERROR)
        ErrorHandling("[Error] connect() : SOCKET_ERROR");

    string str = "hello world! ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    send(hServerSock, str.c_str(), str.size(), 0);
    str = "welcome to TCP/IP! abcdefghijklmnopqrstuvwxyz";
    send(hServerSock, str.c_str(), str.size(), 0);

    Sleep(10);

    for(int i = 0; i < 4;i++)
    {
        strLen = recv(hServerSock, message, sizeof(message)-1, 0);
        message[strLen] = 0;
        cout<<"From Server : "<<message<<endl;
    }


    closesocket(hServerSock);
    
    WSACleanup();
    return 0;
}