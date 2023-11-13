
CC = gcc

CFLAGS = -c -Wall -std=c11 -g -o2 -fopenmp

LDFLAGS = -fopenmp

SRCS= main.c

OBJS = main.o

all: project $(SRCS)

project: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o project
main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

clean:
	rm -rf $(OBJS)