INC_TEST_DRS = -I$(TOP_DIR)/tests/include/

MY_BUILD_DIR = $(BUILD_DIR)/tests/basic_cmocka

CC     = gcc
# CFLAGS =
TEST_LFLAGS = -lcmocka

all: test_do_nothing.out test_failing_test.out

test_do_nothing.out: test_do_nothing.c
	mkdir -p $(MY_BUILD_DIR)
	$(CC) $(INC_TEST_DRS) $^ $(CFLAGS) -o $(MY_BUILD_DIR)/$@ $(LDFLAGS) $(TEST_LFLAGS)

test_failing_test.out: test_failing_test.c
	$(CC) $(INC_TEST_DRS) $^ $(CFLAGS) -o $(MY_BUILD_DIR)/$@ $(LDFLAGS) $(TEST_LFLAGS)

clean:
	rm $(EXE)
	