#ifndef CENG_FRAME_H_
#define CENG_FRAME_H_

#include <time.h>

typedef struct frame_limiter_s {
    clock_t current, next;
    unsigned int fps;
    clock_t time;
} FrameLimiter;

FrameLimiter frame_new(unsigned int fps);
void frame_waitfor(FrameLimiter *self);

#endif // CENG_FRAME_H_