export TOP_DIR = $(PWD)

export INCLUDE_DIR = $(TOP_DIR)/src/include
export SOURCE_DIR = $(TOP_DIR)/src/source
export BUILD_DIR = $(TOP_DIR)/build

export CC = gcc
export CFLAGS = -Wall -g -fsanitize=address
export LDFLAGS = -lm
export TEST_LDFLAGS = -lmocka

test:
	@$(MAKE) -C tests/binary -f binary.mk
	@$(MAKE) -C tests/basic_cmocka -f basic_cmocka.mk

example:
	@$(MAKE) -C examples/binary -f binary.mk
	@$(MAKE) -C examples/concurrency -f concurrency.mk
	@$(MAKE) -C examples/signal -f signal.mk

clean:
	rm -rf build