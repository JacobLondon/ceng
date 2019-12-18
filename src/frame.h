#ifndef CENG_FRAME_H_
#define CENG_FRAME_H_

#include <time.h>
#include <stdbool.h>

typedef struct frame_limiter_s {
    clock_t current, next;
    unsigned int fps;
    clock_t frame_time;
    clock_t clocks_per_frame;
} FrameLimiter;

FrameLimiter *frame_new(unsigned int fps);
void frame_wait(FrameLimiter *self, bool wait);

#endif // CENG_FRAME_H_