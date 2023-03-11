import socket
import multiprocessing as mp


def SendFile(q):
    HOST =  socket.gethostbyname(socket.getfqdn())
    PORT = 9999

    # 소켓 객체를 생성합니다.
    # 주소 체계(address family)로 IPv4, 소켓 타입으로 TCP 사용합니다.
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 포트 사용중이라 연결할 수 없다는
    # WinError 10048 에러 해결를 위해 필요합니다.
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    server_socket.bind((HOST, PORT))
    server_socket.listen()
    while True:
        if not q.empty() :
            fileName = q.get()

            client_socket, addr = server_socket.accept()
            copy = '0'

            while True:
                with open(fileName+'.csv','r') as f:
                    s = f.read()
                    f.close()

                    if copy == s:
                        continue
                    else:
                        print(s)
                        copy = s
                        client_socket.sendall(s.encode())

            client_socket.close()

    server_socket.close()
