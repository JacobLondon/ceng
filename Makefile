CC=gcc
TARGET=ceng

# order by dependency
FRAME_LIMITER=src/frame_limiter
INTERFACE=src/interface

GLOBALS=src/globals
DRAW=src/draw

MAIN=main

OBJS=$(INTERFACE).o $(FRAME_LIMITER).o \
	$(GLOBALS).o $(DRAW).o $(MAIN).o

%.o: %.c
	$(CC) -c $< -o $@
all: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lSDL2 -Wall
	rm $(OBJS)
clean:
	rm $(TARGET) core
