MAKNAM = bistree.mk

INCDRS = -I$(TOP_DIR)/src/include/binary

SRCFLS = binary.c\
         $(TOP_DIR)/src/source/binary/binary.c
         
OBJFLS = binary.o\
         $(TOP_DIR)/src/source/binary/binary.o

EXE    = binary.out

MY_BUILD_DIR = $(BUILD_DIR)/examples/binary

CC     = gcc
# CFLAGS =
# LFLAGS =

$(EXE):
	mkdir -p $(MY_BUILD_DIR)
	$(CC) $(INCDRS) $(SRCFLS) $(CFLAGS) $(LDFLAGS) -o $(MY_BUILD_DIR)/$@ 
# $(EXE): $(OBJFLS)
# 	$(LL) $(LFLAGS) -o $@ $(OBJFLS) $(LIBDRS) $(LIBFLS)

# .c.o:
# 	$(CC) $(CFLAGS) -o $@ -c $(INCDRS) $<

# test_binary: binary.o $(TEST_DIRS)/test_binary.c
# 	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o test_binary -lcmocka

# $(OBJFLS): $(SRCFLS)
# 	$(CC) $(CPPFLAGS) $(CFLAGS) -c $^ -o $@ 

clean:
	rm $(EXE)
	