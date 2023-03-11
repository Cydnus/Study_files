cc=gcc
cpp=g++
exe=.out
libwp=-lwiringPi
libmq=-lrt

target=baseball

all : 01_Baseball.cpp Baseball.cpp I2C_LCD.cpp
	${cpp} $^  ${libwp} ${libmq} -o ${target}${exe} 
	sudo ./${target}${exe} 

pin : 02_PIN_TEST.cpp I2C_LCD.cpp
	${cpp} $^  ${libwp} -o $@${exe} 
	sudo ./$@${exe} 

run: ${target}${exe}
	sudo ./$^


remove : 
	rm -rf *$(exe)