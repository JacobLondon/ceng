#ifndef FRAME_LIMITER_H
#define FRAME_LIMITER_H

#include <time.h>

#define USEC_CONVERSION 1000000.0

/**
 * \brief Limit the speed of a loop to a specified frame (iteration) rate.
 */
typedef struct FrameLimiter {
    double target_fps;  // target frames per second
    double fps;         // actual frames per second
    double frame_time;  // time spent in the frame
    long target_uspf;   // target microseconds per frame
    long actual_uspf;   // actual microseconds per frame
    long usleft;
    clock_t timestamp;
} FrameLimiter;

/**
 * \brief FrameLimiter initializer, specify the target frames per second.
 */
#define FRAME_LIMITER_INIT(_target_fps) { \
    .target_fps = _target_fps, \
    .fps = 0, \
    .frame_time = 0, \
    .target_uspf = (long)(USEC_CONVERSION / _target_fps), \
    .actual_uspf = 0, \
    .usleft = 0, \
    .timestamp = clock(), \
}

/**
 * \brief Wait until the frame has reached its target frame (iteration) rate.
 */
void frame_limiter_wait(struct FrameLimiter* self);

#endif // FRAME_LIMITER_H