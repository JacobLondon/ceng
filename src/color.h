#ifndef CENG_COLOR_H_
#define CENG_COLOR_H_

/**
 * @brief Hold 8 bit RGBA values.
 */
typedef struct color_s {
    unsigned char r, g, b, a;
} Color;

#define WHITE (Color){255, 255, 255, 255}
#define BLACK (Color){0, 0, 0, 255}
#define RED   (Color){255, 0, 0, 255}
#define GREEN (Color){0, 255, 0, 255}
#define BLUE  (Color){0, 0, 255, 255}

#endif // COLOR_H_