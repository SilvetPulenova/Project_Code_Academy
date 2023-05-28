# Pro*C Makefile
PROCC=proc code=ANSI_C include=./include
CC=gcc
INC=-I. -I./include -I$(ORACLE_HOME)/sdk/include
CFLAGS=-Wall -g $(INC) -std=gnu11
LIBS=-L$(ORACLE_HOME)/lib/ -lclntsh

HEADERS=$(shell find . -name "*.h")
PCFILES=$(shell find . -name "*.pc")
CFILES=$(shell find ./csrc -name "*.c")
CSRC=$(PCFILES:.pc=.c)
LSRC=$(PCFILES:.pc=.lis)
OBJ=$(PCFILES:.pc=.o)$(CFILES:.c=.o)
TARGET=main

%.c:%.pc
	$(PROCC) $<
	
%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) $< -c -o $@
	
$(TARGET): $(OBJ)
	$(CC) $(LIBS) $^ -o $@
	
.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJ) $(CSRC) $(LSRC)
	