
CFLAGS = -g -Wall
LDFLAGS = -lpthread

all: basic_thread.out mutex.out thread.out

basic_thread.out: basic_thread.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

mutex.out: mutex.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

thread.out: thread.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm *.out