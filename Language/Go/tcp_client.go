package main

import (
	"fmt"
	"net"
	"os"
	_ "time"
)

func main() {

	var address string
	var name string

	args := os.Args

	switch len(args) {
	case 2:
		name = args[1]
		address = "localhost:8004"
		break
	case 3:
		name = args[1]
		address = args[2] + ":8004"
		break
	case 4:
		name = args[1]
		address = args[2] + ":" + args[4]
		break
	case 1:
		fallthrough
	default:
		fmt.Println("Useage : ", args[0], " name (ip) (port)")
		return
	}

	client, err := net.Dial("tcp", address)
	chanStringMSG := make(chan string)

	if err != nil {
		fmt.Println(err)
		return
	}
	defer client.Close()

	go func(c net.Conn) {
		data := make([]byte, 4096)
		for {
			n, err := c.Read(data)
			if err != nil {
				fmt.Println(err)
				return
			}

			if string(data[:n]) == "FIN_GOODBYE" {
				fmt.Println(string(data[4:n]))
				c.Close()
				os.Exit(1)
			}
			fmt.Println(string(data[:n]))

			//time.Sleep(1*time.Second)
		}
	}(client)

	go func(c net.Conn) {
		for {
			s := <-chanStringMSG
			_, err := c.Write([]byte(s))
			if err != nil {
				fmt.Println(err)
				return
			}
			//time.Sleep(1 * time.Second)
		}
	}(client)

	chanStringMSG <- "[System] " + name + " 님이 연결되었습니다"

	for {
		var inputs string
		fmt.Scanln(&inputs)

		if inputs != "FIN" {
			inputs = name + " : " + inputs
		} else {
			inputs = inputs + name
		}
		chanStringMSG <- inputs
	}

}
