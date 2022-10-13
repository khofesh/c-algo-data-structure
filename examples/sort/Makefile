CC :=gcc
LDFLAGS :=
CFLAGS := -g -Wall -lm
C_SOURCES :=$(wildcard *.c)
C_EXECUTABLE :=$(C_SOURCES:.c=)

all:$(C_EXECUTABLE)

$(C_EXECUTABLE):$(C_SOURCES)
	$(CC) $< $(LDFLAGS) $(CFLAGS) -o $@

clean:
	rm -rf $(C_EXECUTABLE)