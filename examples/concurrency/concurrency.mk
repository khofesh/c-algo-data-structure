
CFLAGS = -g -Wall
LDFLAGS = -lpthread

MY_BUILD_DIR = $(BUILD_DIR)/examples/concurrency

all: basic_thread.out mutex.out thread.out

basic_thread.out: basic_thread.c
	mkdir -p $(MY_BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(MY_BUILD_DIR)/$@

mutex.out: mutex.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(MY_BUILD_DIR)/$@

thread.out: thread.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(MY_BUILD_DIR)/$@

clean:
	rm *.out