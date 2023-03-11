pp=g++
cc=gcc
lib=lwiringPi

all : 

hello : 01_hello.cpp
	$(pp) -o $@ $^
	
example1 : 04_Example.cpp
	$(cc) -o $@ -DDEBUG=1 $^ -$(lib)

example2 : 04_Example.cpp
	$(cc) -o $@ -DDEBUG=2 $^ -$(lib)

example3 : 04_Example.cpp
	$(cc) -o $@ -DDEBUG=3 $^ -$(lib)
	
example4 : 04_Example.cpp
	$(cc) -o $@ -DDEBUG=4 $^ -$(lib)