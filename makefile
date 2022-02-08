#!/usr/bin/make
CFLAGS = -g -Wall -Werror -fsanitize=address
C_SRC_FILES  = $(wildcard *.c)
OBJ_FILES := $(patsubst %.c, %, ${C_SRC_FILES})

.PHONY: all clean

% : %.c
	cc $(CFLAGS) $^ -o $@ 

all : ${OBJ_FILES}

clean :
	rm -f $(OBJ_FILES)
