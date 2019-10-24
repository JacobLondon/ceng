#ifndef CENG_ARRAY_H_
#define CENG_ARRAY_H_

#include <stdlib.h>

#define ARRAY_DEFAULT_LEN 8
#define ARRAY_RESIZE_AMT 2

typedef struct array_s {
    void (* data_free)(void *data);
    void *data;
    size_t data_size;
    size_t end;
    size_t len;
} Array;

Array *array_new(size_t data_size, void (* data_free)(void *data));
void array_free(Array *self);
void array_append(Array *self, void *value);

#endif // CENG_ARRAY_H_