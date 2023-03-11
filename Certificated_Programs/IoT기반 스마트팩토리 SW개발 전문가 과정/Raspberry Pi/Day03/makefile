cc=gcc
exe=.out
libwp=-lwiringPi
libmq=-lrt

target=example

all :

${target}01 : 01_Interrupt_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}02 : 02_Interrupt_Ex02.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}03 : 03_Thread_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}04 : 04_MessageQueue_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libmq}
	sudo ./$@${exe}

${target}05 : 05_MessageQueue_Ex02.cpp
	$(cc) -o $@${exe} $^ ${libmq} ${libwp}
	sudo ./$@${exe}


${target}06 : 06_RSP.cpp
	$(cc) -o $@${exe} $^ ${libmq} ${libwp}
	sudo ./$@${exe}


remove : 
	rm -rf *$(exe)