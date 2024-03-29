TARGET=ceng
WINTARGET=ceng.exe

CC=gcc
CFLAGS=-lSDL2 -lSDL2main -O2 -Wall -Wextra -lm

OBJ_FILES=src/array.o src/context.o src/frame.o src/painter.o src/window.o \
		  demo/circle.o demo/first.o demo/cast.o \
		  main.o

.PHONY: clean

$(TARGET) : $(OBJ_FILES)
	$(CC) -o $(TARGET) $(OBJ_FILES) $(CFLAGS)

clean:
	rm -rf $(TARGET) $(WINTARGET) $(OBJ_FILES) core
