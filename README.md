# c-algo-data-structure

algorithms and data structure in C

## cmocka

install dependencies

```shell
sudo dnf install libcmocka-devel
```

## build tests

```shell
make tests
```

## references

https://gist.github.com/wkentaro/4156dfc7922437a9ff60
https://www.testcookbook.com/book/c/unit-test-with-cmocka.html
https://stackoverflow.com/questions/29945791/undefined-reference-to-cmocka-run-group-tests-when-running-sample-cmocka-te

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
		rm -rf $(EXECUTABLE)
```
