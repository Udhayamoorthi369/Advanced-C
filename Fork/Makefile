makefile for building demo applications.
# by udhayamoorthi

# Edit this file to compile extra C files into their own programs.
TARGETS=fork_Wait

CROSS_TOOL = 
CC_CPP = $(CROSS_TOOL)g++
CC_C = $(CROSS_TOOL)gcc

CFLAGS = -Wall -g -std=c99 -Werror

all: clean $(TARGETS)

$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c -o $@

clean:
