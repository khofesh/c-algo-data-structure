CC = gcc
CFLAGS = -g -Wall -fsanitize=address

SRCS := $(shell find . -name '*.c')

compile:
	$(CC) $(CFLAGS) $(SRCS) -o main

clean: 
	rm -f main