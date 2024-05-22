### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

LIBS = -lm

###
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer

.PHONY: exec
exec: ./shell.c
	@$(CC) $(CFLAGS) -o Shell Shell.c
	@./Shell

.PHONY: test
test: tests.out
	@./tests.out

.PHONY: clean
clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: ./test_shell.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) test-framework/unity.c ./test_shell.c -o tests.out $(LIBS)
