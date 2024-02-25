CC=g++
CFLAGS=-c -Wall -std=c++11

all: main

main: main.o Node.o
	$(CC) main.o Node.o -o main

main.o: main.cpp Node.h
	$(CC) $(CFLAGS) main.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) Node.cpp

clean:
	rm -rf *.o main

