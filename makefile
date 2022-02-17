#!/usr/bin/make
CFLAGS = -g -Wall -Werror -fsanitize=address
C_SRC_FILES = $(ENV_SRC_FILES)
C_SRC_FILES += $(wildcard *.c)
CPP_SRC_FILES = $(ENV_SRC_FILES)
CPP_SRC_FILES += $(wildcard *.cpp)
OBJ_FILES := $(patsubst %.c, %, ${C_SRC_FILES})
OBJ_FILES_CPP := $(patsubst %.cpp, %, ${CPP_SRC_FILES})

.PHONY: all cpp clean

% : %.c
	cc $(CFLAGS) $^ -o $@ 

% : %.cpp
	g++ $(CFLAGS) $^ -o $@

all : ${OBJ_FILES}

cpp : ${OBJ_FILES_CPP}

clean :
	rm -f $(OBJ_FILES) $(OBJ_FILES_CPP)
