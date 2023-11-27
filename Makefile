
CC = gcc

CFLAGS = -c -Wall -std=c11 -g -o2 -fopenmp

LDFLAGS = -fopenmp

SRCS= main.c check.c functions.c

OBJS = main.o check.o functions.o

all: project $(SRCS)

project: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o project
main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o
check.o: check.c
	$(CC) $(CFLAGS) check.c -o check.o
functions.o: functions.c
	$(CC) $(CFLAGS) functions.c -o functions.o
clean:
	rm -rf $(OBJS)