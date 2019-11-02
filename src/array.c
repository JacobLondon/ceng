#include <stdlib.h>

#include "array.h"

Array *array_new(size_t data_size, void (* data_free)(void *data))
{
    Array *self = malloc(sizeof(Array));
    self->data_free = data_free;
    self->data  = malloc(data_size * ARRAY_DEFAULT_LEN);
    self->data_size = data_size;
    self->end   = 0;
    self->len = ARRAY_DEFAULT_LEN;

    return self;
}

void array_free(Array *self)
{
    if (!self)
        return;
    
    if (self->data && self->data_free)
        self->data_free(self->data);
    
    free(self);
}

void array_append(Array *self, void *value)
{
    // realloc for more space
    if (self->end == self->len)
        self->data = realloc(self->data, self->len * ARRAY_RESIZE_AMT);

    *((&self->data) + self->end++) = value;
}
