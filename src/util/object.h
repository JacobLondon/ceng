#ifndef OBJECT_H
#define OBJECT_H

typedef struct Object {
    int x, y, z;
    int w, h;
    void (* draw)(struct Object* self);
} Object;

#define OBJECT_INIT { \
    .x = 0, \
    .y = 0, \
    .z = 1, \
    .w = 0, \
    .h = 0, \
}

void object_construct(struct Object* self, void (*)(struct Object*));
void object_setup();
void object_transform(struct Object* self);

#endif // OBJECT_H