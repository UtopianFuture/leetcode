#!/usr/bin/make
CFLAGS = -g -Wall -fsanitize=address
C_SRC_FILES = $(ENV_SRC_FILES)
C_SRC_FILES += $(wildcard *.c)
CPP_SRC_FILES = $(ENV_SRC_FILES)
CPP_SRC_FILES += $(wildcard *.cpp)
OBJ_FILES := $(patsubst %.c, object/%, ${C_SRC_FILES})
OBJ_FILES_CPP := $(patsubst %.cpp, object/%, ${CPP_SRC_FILES})

.PHONY: all c cpp clean

object/% : %.c
	cc $(CFLAGS) $^ -o $@

object/% : %.cpp
	g++ $(CFLAGS) $^ -o $@

c : ${OBJ_FILES}

cpp : ${OBJ_FILES_CPP}

all: c cpp

clean :
	rm -f $(OBJ_FILES) $(OBJ_FILES_CPP)
