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

ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

.PHONY: setup_zsh
setup_zsh:
	@echo "export PATH=$$PATH:$(ROOT_DIR)" >> ~/.zshrc
	@zsh
	@source ~/.zshrc

.PHONY: setup_bash
setup_bash:
	@echo "export PATH=$$PATH:$(ROOT_DIR)" >> ~/.bash_profile
	@source ~/.bash_profile

.PHONY: compile
compile: ./shell.c
	@$(CC) $(CFLAGS) -o pcshell shell.c

.PHONY: test
test: tests.out
	@./tests.out

.PHONY: clean
clean:
	rm -rf *.o *.out *.out.dSYM *.dSYM pcshell

tests.out: ./test_shell.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) test-framework/unity.c ./test_shell.c -o tests.out $(LIBS)
