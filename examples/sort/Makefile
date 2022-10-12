CC = gcc
CFLAGS = -g -Wall -lm

SRCS := $(shell find . -name '*.c')

compile:
	$(CC) $(CFLAGS) $(SRCS) -o main

clean: 
	rm -f main