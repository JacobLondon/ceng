#ifndef CENG_ARRAY_H_
#define CENG_ARRAY_H_

#include <stdlib.h>

#define ARRAY_DEFAULT_LEN 8
#define ARRAY_RESIZE_AMT 2

typedef struct array_s {
    void (* free_fn)(void *buf);
    void **buf;
    size_t end;
    size_t size;
} Array;

Array *array_new(void (* free_fn)(void *buf));
void array_free(Array *self);
void array_push(Array *self, void *value);
void array_pop(Array *self);

#endif // CENG_ARRAY_H_