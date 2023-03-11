cc=gcc
exe=.out
libwp=-lwiringPi
libmq=-lrt

target=example

all :

${target}01 : 01_Ch03_11_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}02 : 02_Ch03_11_Ex02.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}
	
${target}03 : 03_Ch03_11_Ex03.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}04 : 04_Ch03_11_Ex04.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}05 : 05_Ch03_12_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}06 : 06_Ch03_12_Ex02.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}07 : 07_Ch03_12_Ex03.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}08 : 08_Ch03_12_Ex04.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}09 : 09_Ch03_21_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}10 : 10_Ch03_31_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}11 : 11_Ch03_41_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}12 : 12_Ch03_42_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}13 : 13_Ch03_43_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp}
	sudo ./$@${exe}

${target}14 : 14_Ch03_51_Ex01.cpp
	$(cc) -o $@${exe} $^ ${libwp} -lrt
	sudo ./$@${exe}


remove : 
	rm -rf *$(exe)