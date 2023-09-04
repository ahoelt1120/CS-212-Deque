CC=gcc
CFLAGS=-W -Wall -g
OBJECTS = project3B.o project3B_deque.o

all: project3B
project3B: project3B.o $(OBJECTS)
	$(CC) $(CFLAGS) -o project3B $(OBJECTS)

project3B.o: project3B.c project3B_deque.h
project3B_deque.o: project3B_deque.c project3B_deque.h

clean:
	rm -f proj $(OBJECTS)



