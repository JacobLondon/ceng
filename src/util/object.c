#include "object.h"
#include "../color.h"
#include "../globals.h"

void draw_square(struct Object* self);

void object_setup()
{
    struct Object square = OBJECT_INIT;
    object_construct(&square, draw_square);
    interface_append_object(&interface, square);
}

void object_construct(struct Object* self, void (*func)(struct Object*))
{
    self->draw = func;
}

void object_transform(struct Object* self)
{
    self->w *= self->z;
    self->h *= self->z;
}

void draw_square(struct Object* self)
{
    interface_draw_color(&interface, BLACK);
    SDL_Rect r = {self->x, self->y, self->w, self->h};
    SDL_RenderFillRect(renderer, &r);
}
