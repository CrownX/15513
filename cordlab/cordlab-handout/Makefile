#
# Makefile for cordlab
#
SHELL = /bin/bash
# For shark machines
CC = $(LLVM_PATH)clang
# For local system
#CC = /usr/bin/clang
CFLAGS = -O0 -g -Werror -std=c99

# Path to LLVM binaries
LLVM_PATH = /usr/local/depot/llvm-7.0/bin/
ifneq (,$(wildcard /usr/lib/llvm-7/bin/))
  LLVM_PATH = /usr/lib/llvm-7/bin/
endif

# Targets to compile
HANDIN_TAR = cordlab-handin.tar
FILES = cord-test $(HANDIN_TAR)

.PHONY: all
all: $(FILES)

# Object files
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Header dependencies
cord.o: cord-interface.h xalloc.h
cord-test.o: cord-interface.h

# Linking rules
cord-test: cord.o cord-test.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Test
.PHONY: test
test: cord-test
	./cord-test

# Files used in autograder only
ifneq ($(AUTOGRADER),)
  ext-interface.h: cord-interface-grader.h
  makesomecords.c: ext-interface.h
  grade-iscord.c: ext-interface.h
  grade-basic.c: ext-interface.h
  grade-rec.c: ext-interface.h
  grade-sub.c: ext-interface.h

  iscord: grade-iscord.o cord.o makesomecords.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
  basic: grade-basic.o cord.o makesomecords.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
  rec: grade-rec.o cord.o makesomecords.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
  sub: grade-sub.o cord.o makesomecords.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

  .PHONY: autograde
  autograde: iscord basic rec sub
endif

.PHONY: clean
clean:
	rm -rf $(FILES)
	rm -rf *.o *~ *.dSYM

# Include rules for submit, format, etc
FORMAT_FILES = cord.c
HANDIN_FILES = cord.c .clang-format
include helper.mk

# Add check-format dependencies
submit: | check-format
$(FILES): | check-format
