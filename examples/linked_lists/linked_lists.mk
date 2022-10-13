SRCFLS = $(TOP_DIR)/src/source/linked_lists/singly_linked.c

INCDRS = -I$(TOP_DIR)/src/include/linked_lists

MY_BUILD_DIR = $(BUILD_DIR)/examples/linked_lists

all: singly_linked.out

singly_linked.out: singly_linked.c
	mkdir -p $(MY_BUILD_DIR)
	$(CC) $(INCDRS) $(SRCFLS) $(CFLAGS) $(LDFLAGS) $^ -o $(MY_BUILD_DIR)/$@

clean:
	rm *.out