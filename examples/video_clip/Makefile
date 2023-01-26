C = gcc
CFLAGS = -fsanitize=address -Wall -g -fdiagnostics-color=always

SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

all: main

main: $(OBJ_FILES)
	$(C) $(CFLAGS) -o $@ $^

%.o: %.c
	$(C) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f main *.o
