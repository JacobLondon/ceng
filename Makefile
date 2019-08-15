CC=gcc
CFLAGS=-lSDL2 -Wall -ggdb
TARGET=ceng

# order by dependency

FRAME_LIMITER=src/frame_limiter
INTERFACE=src/interface

GLOBALS=src/globals

DRAW=src/util/draw
CONTROL=src/util/control
OBJECT=src/util/object

MAIN=main

OBJS=$(INTERFACE).o $(FRAME_LIMITER).o \
	$(GLOBALS).o \
	$(DRAW).o $(CONTROL).o $(OBJECT).o \
	$(MAIN).o

%.o: %.c
	$(CC) -c $< -o $@
all: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)
	rm $(OBJS)
clean:
	rm $(TARGET) $(OBJS) core
