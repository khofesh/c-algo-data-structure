export TOP_DIR = $(PWD)

export INCLUDE_DIR = $(TOP_DIR)/src/include
export SOURCE_DIR = $(TOP_DIR)/src/source

export CC = gcc
export CFLAGS = -Wall -g
export LDFLAGS = -lm
export TEST_LDFLAGS = -lmocka

fuck:
	@$(MAKE) -C examples/binary -f binary.mk

clean:
	@$(MAKE) -C examples/binary -f binary.mk clean