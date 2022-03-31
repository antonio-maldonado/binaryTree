#http://www.cplusplus.com/forum/unices/12499/#msg59885
CC           = g++
CFLAGS   = -ansi -Wall
LDFLAGS = 

all: test clean

test: main.o List.o Stack.o Node.o Queue.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: arbol0.cpp
	$(CC) -o $@ -c $(CFLAGS) $<

List.o: libs/List.cpp libs/List.h
	$(CC) -o $@ -c $(CFLAGS) $<

Queue.o: libs/Queue.cpp libs/Queue.h
	$(CC) -o $@ -c $(CFLAGS) $<

Stack.o: libs/stack.cpp libs/stack.h
	$(CC) -o $@ -c $(CFLAGS) $<

Node.o: libs/Node.cpp libs/Node.h
	$(CC) -o $@ -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm test


