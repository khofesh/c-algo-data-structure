export TOP_DIR = $(PWD)

export INCLUDE_DIR = $(TOP_DIR)/src/include
export SOURCE_DIR = $(TOP_DIR)/src/source

export CC = gcc
export CFLAGS = -Wall -g
export LDFLAGS = -lm
export TEST_LDFLAGS = -lmocka

example:
	@$(MAKE) -C examples/binary -f binary.mk
	@$(MAKE) -C examples/concurrency -f concurrency.mk
	@$(MAKE) -C examples/signal -f signal.mk

clean:
	@$(MAKE) -C examples/binary -f binary.mk clean
	@$(MAKE) -C examples/concurrency -f concurrency.mk clean
	@$(MAKE) -C examples/signal -f signal.mk clean