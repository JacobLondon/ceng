#ifndef COLOR_H
#define COLOR_H

/**
 * \brief Hold 8 bit RGBA values.
 */
typedef struct Color {
    unsigned char r, g, b, a;
} Color;

#define COLOR(color) (struct Color){color}
#define WHITE 255, 255, 255, 255
#define BLACK 0, 0, 0, 255
#define RED   255, 0, 0, 255
#define GREEN 0, 255, 0, 255
#define BLUE  0, 0, 255, 255

#endif // COLOR_H