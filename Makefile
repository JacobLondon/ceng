TARGET=ceng

CC=gcc
CFLAGS=-lSDL2 -O2 -Wall -Wextra

OBJ_FILES=src/array.o src/context.o src/globals.o src/painter.o src/window.o \
		  main.o

.PHONY: clean

$(TARGET) : $(OBJ_FILES)
	$(CC) -o $(TARGET) $(OBJ_FILES) $(CFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ_FILES) core
