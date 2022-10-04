INCDRS = -I$(TOP_DIR)/src/include/binary

INC_TEST_DRS = -I$(TOP_DIR)/tests/include/

SRCFLS = $(TOP_DIR)/src/source/binary/binary.c

EXE    = test_binary.out

MY_BUILD_DIR = $(BUILD_DIR)/tests/binary

CC     = gcc
# CFLAGS =
TEST_LFLAGS = -lcmocka

all: test_binary.out

test_binary.out: test_binary.c
	mkdir -p $(MY_BUILD_DIR)
	$(CC) $(INCDRS) $(INC_TEST_DRS) $^ $(SRCFLS) $(CFLAGS) -o $(MY_BUILD_DIR)/$@ $(LDFLAGS) $(TEST_LFLAGS)

clean:
	rm $(MY_BUILD_DIR)/$(EXE)
	