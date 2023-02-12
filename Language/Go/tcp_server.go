package main

import (
	"fmt"
	"net"
	"runtime"	
	"sync"
)

var connArr []net.Conn
var mutex *sync.Mutex

func findIndex(c net.Conn, start int, end int) int {

	if start > end {
		return -1
	}
	mid := (start + end) / 2

	if connArr[mid] == c {
		return mid
	}
	ret := findIndex(c, start, mid-1)
	if ret == -1 {
		ret = findIndex(c, mid+1, end)
	}
	return ret
}

func RemoveConn(c net.Conn) {

	ind := findIndex(c, 0, len(connArr))
	
	mutex.Lock()
	copy(connArr[ind:], connArr[ind+1:])
	connArr = connArr[:len(connArr)-1]
	mutex.Unlock()

	_, err := c.Write([]byte("FIN_GOODBYE"))
	if err != nil {
		fmt.Println(err)
		return
	}
}

func requestHandler(c net.Conn) {
	data := make([]byte, 4096)
	for {
		n, err := c.Read(data)

		if err != nil {
			fmt.Println(err)
			return
		}

		fmt.Println(string(data[:n]))

		if string(data[:n])[:3] == "FIN" {
			fmt.Println(c.RemoteAddr().String(), "님이 연결을 종료하였습니다.")
			for con := range connArr {
				if connArr[con] == c {
					continue 
				}

				_, err := connArr[con].Write([]byte("[System] " + string(data[:n])[3:] + " 님이 연결을 종료하였습니다."))
				if err != nil {
					fmt.Println(err)
					return
				}
			}
			RemoveConn(c)

			c.Close()
			return
		} else {
			//fmt.Println(connArr)
			for con := range connArr {
				if connArr[con] == c {
					continue
				}

				_, err := connArr[con].Write((data[:n]))
				if err != nil {
					fmt.Println(err)
					return
				}
			}
		}	
		runtime.Gosched()
	}
}

func main() {

	runtime.GOMAXPROCS(2)

	mutex = &sync.Mutex{}

	ln, err := net.Listen("tcp", ":8004")

	if err != nil {
		fmt.Println(err)
		return
	}
	defer ln.Close()

	fmt.Println("[Server] Server is opening")
	fmt.Println("[Server] Listenning...")

	for {
		conn, err := ln.Accept()

		if err != nil {
			fmt.Println(err)
			continue
		}
		defer conn.Close()

		fmt.Println("[Server] " + conn.RemoteAddr().String() + " is Accepted! ")
		connArr = append(connArr, conn)

		go requestHandler(conn)
	}

}
