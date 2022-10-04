
CFLAGS = -g -Wall

MY_BUILD_DIR = $(BUILD_DIR)/examples/signal

all: multiplication.out sigaction_sample.out

multiplication.out: multiplication.c
	mkdir -p $(MY_BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(MY_BUILD_DIR)/$@

sigaction_sample.out: sigaction_sample.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(MY_BUILD_DIR)/$@

clean:
	rm *.out