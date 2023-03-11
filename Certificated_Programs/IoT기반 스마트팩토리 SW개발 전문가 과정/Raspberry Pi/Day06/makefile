cc=gcc
cpp=g++
exe=.out
libwp=-lwiringPi
libmq=-lrt

target=example

all : 

${target}01 : 01_Serial_Ex01.cpp
	${cc} $^  ${libwp} -o $@${exe} 
	sudo ./$@${exe} 



remove : 
	rm -rf *$(exe)