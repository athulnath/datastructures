CC=g++
CFLAGS=-c 

all: stackDriver.o Stack.o 
	$(CC) stackDriver.o Stack.o -o stack-run.o

stackDriver.o: stackDriver.cpp
	$(CC) $(CFLAGS) stackDriver.cpp -o stackDriver.o
	
clean:
	rm -rf *.o
