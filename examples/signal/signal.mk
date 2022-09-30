
CFLAGS = -g -Wall

all: multiplication.out sigaction_sample.out

multiplication.out: multiplication.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

sigaction_sample.out: sigaction_sample.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm *.out