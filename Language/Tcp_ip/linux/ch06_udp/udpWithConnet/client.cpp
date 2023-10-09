#include <iostream>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>
#include <unistd.h>

#define BUFSIZE 30

using namespace std;

void error_handleing(string msg)
{
    cerr<<msg<<endl;
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock;
    char message[BUFSIZE];
    int str_len, addr_size;

    struct sockaddr_in serv_addr;
    struct sockaddr_in from_addr;

    if(argc != 3)
    {
        cout<<"Useage : " << argv[0] << " <IP> <PORT>"<<endl;
        exit(1);  
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);

    if(sock == -1)
        error_handleing("[Error] socket() : INVALID_SOCKET");
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    
    connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    while(true)
    {
        cout<<"전송할 메시지를 입력하세요 (q to quit) :";
        string str;
        cin>>str;
        if(str == "q") break;
        
        write(sock, str.c_str(), str.size());

        addr_size = sizeof(from_addr);
        str_len = read(sock, message, BUFSIZE-1);
        message[str_len] = 0;
        cout<<message<<endl;
    }
    
    close(sock);
    return 0;
}
