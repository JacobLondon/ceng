CC=gcc
TARGET=ceng

# objects
frame_limiter=interface/frame_limiter
interface=interface/interface
# highest level
globals=util/globals
draw_functions=graphics/draw
main=main

objectfiles=$(interface).o $(frame_limiter).o \
	$(globals).o $(draw_functions).o $(main).o

%.o: %.c
	$(CC) -c $< -o $@

all: $(objectfiles)
	$(CC) $(objectfiles) -o $(TARGET) -lSDL2 -Wall
clean:
	rm $(objectfiles) $(TARGET) core
