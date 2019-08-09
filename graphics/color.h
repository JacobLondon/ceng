#ifndef COLOR_H
#define COLOR_H

typedef struct Color {
    unsigned char r, g, b, a;
} Color;

#define WHITE 255, 255, 255, 255
#define BLACK 0, 0, 0, 255
#define RED   255, 0, 0, 255
#define GREEN 0, 255, 0, 255
#define BLUE  0, 0, 255, 255

#endif // COLOR_H