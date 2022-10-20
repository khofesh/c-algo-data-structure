# c-algo-data-structure

algorithms and data structure in C

## cmocka

install dependencies

```shell
sudo dnf install libcmocka-devel
```

## build tests

```shell
make test
```

## build examples

```shell
make example
```

## secure programming

- https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard
- https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines

## for template

- https://github.com/pantuza/c-project-template

# Makefile examples

```make
CC :=gcc
CPP :=g++
LDFLAGS :=
C_SOURCES :=$(wildcard *.c)
C_EXECUTABLE :=$(C_SOURCES:.c=)
CPP_SOURCES :=$(wildcard *.cpp)
CPP_EXECUTABLE :=$(CPP_SOURCES:.cpp=)

all:$(C_EXECUTABLE) $(CPP_EXECUTABLE)

$(C_EXECUTABLE):$(C_SOURCES)
	$(CC) $< $(LDFLAGS) $(CFLAGS) -o $@

$(CPP_EXECUTABLE):$(CPP_SOURCES)
	$(CPP) $< $(LDFLAGS) $(CFLAGS) -o $@

clean:
	rm -rf $(C_EXECUTABLE)
	rm -rf $(CPP_EXECUTABLE)
```

sample for compiling a unit test

```shell
gcc -I./src/include/binary/ tests/test_binary.c src/source/binary/binary-to-decimal.c src/source/binary/decimal-to-binary.c -Wall -g -lm -o ./build/tests/test_binary -lcmocka

gcc -I./src -I./src/include -I./src/include/binary -I./src/source -I./src/source/binary -I./src/example -MMD -MP tests/test_binary.c -Wall -g -lm -o ./build/tests/test_binary -lcmocka
```

# TODOs

- clean up `examples/sort` and `examples/recursion`
- `singly_linked.c` fix AddressSanitizer: attempting double-free

# References

- Mastering algorithms with C
- Understanding and Using C Pointers
- https://gist.github.com/wkentaro/4156dfc7922437a9ff60
- https://www.testcookbook.com/book/c/unit-test-with-cmocka.html
- https://stackoverflow.com/questions/29945791/undefined-reference-to-cmocka-run-group-tests-when-running-sample-cmocka-te
- https://blog.microjoe.org/2017/unit-tests-c-cmocka-coverage-cmake.html#complete-example
- https://stackoverflow.com/questions/17896751/makefile-use-multiple-makefiles
- https://stackoverflow.com/questions/59630531/multiple-makefile-for-a-single-project
