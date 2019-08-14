#ifndef COLOR_H
#define COLOR_H

/**
 * \brief Hold 8 bit RGBA values.
 */
typedef struct Color {
    unsigned char r, g, b, a;
} Color;

#define WHITE (struct Color){255, 255, 255, 255}
#define BLACK (struct Color){0, 0, 0, 255}
#define RED   (struct Color){255, 0, 0, 255}
#define GREEN (struct Color){0, 255, 0, 255}
#define BLUE  (struct Color){0, 0, 255, 255}

#endif // COLOR_H