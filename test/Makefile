# =========================================================================
#   Unity - A Test Framework for C
#   ThrowTheSwitch.org
#   Copyright (c) 2007-24 Mike Karlesky, Mark VanderVoord, & Greg Williams
#   SPDX-License-Identifier: MIT
# =========================================================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

CC=gcc
ifeq ($(shell uname -s), Darwin)
CC=clang
endif


CFLAGS=-std=c99 -Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wstrict-prototypes -Wundef -Wold-style-definition

DIRS= . util

TARGET=all_tests$(TARGET_EXTENSION)
UNITY_ROOT=../Unity
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
CFLAGS+=$(INC_DIRS)
SYMBOLS=-DUNITY_FIXTURE_NO_EXTRAS
CFLAGS+=$(SYMBOLS)
DEPS=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  util/varint_tests.c \
  util/varint_runner_tests.c \
  all_tests.c

all: clean default

default:
	$(CC) $(CFLAGS) $(DEPS) -o $(TARGET)
	- ./$(TARGET) -v

clean:
	$(CLEANUP) $(TARGET)

ci: CFLAGS += -Werror
ci: default
