#include <stdio.h>
#include <math.h>

#include "demo.h"

/**
 * Globals
 */

static Context *ctx;
static Window *window;

// custom globals
static bool call_keys = true;
static bool call_draw = true;

float px = 8.0f;
float py = 8.0f;
float pa = 0.0f;
float fov = 3.14159 / 3.0;
float step = 3.0f;
float rot_r = 2.0f;
float rot_l = -2.0f;
#define map_width 16
#define map_height 16
char wall_char = '#';
int depth = 16;
float cast_step = 0.1f;
char map[map_width][map_height] = {
    "################",
    "#..............#",
    "#...........#..#",
    "#....##........#",
    "#..........##..#",
    "#..............#",
    "#..............#",
    "#......#.......#",
    "#......#.......#",
    "#......#.......#",
    "#..............#",
    "#.....###..#####",
    "#..............#",
    "#........##....#",
    "#..............#",
    "################",
};
int walk_step = 2;

/**
 * Event functions
 */

static void move(int direction, int strafe, int step)
{
    px += direction * sinf(pa + strafe * 3.14159 / 2.0f) * step * 0.05;
    py += direction * cosf(pa + strafe * 3.14159 / 2.0f) * step * 0.05;

    // collision detection
    if (map[(int)py][(int)px] == wall_char) {
        if (strafe != 0)
            direction = -1;
        px -= direction * sinf(pa - strafe * 3.14159 / 2) * step * 0.05;
        py -= direction * cosf(pa - strafe * 3.14159 / 2) * step * 0.05;
    }
}

static void keys()
{
    if (ctx->keystate[SDL_SCANCODE_ESCAPE]) {
        printf("Exiting...\n");
        ctx->window->quit = true;
    }
    if (ctx->keystate[SDL_SCANCODE_LEFT]) {
        pa += rot_l * 0.035;
    }
    if (ctx->keystate[SDL_SCANCODE_RIGHT]) {
        pa += rot_r * 0.035;
    }
    if (ctx->keystate[SDL_SCANCODE_W]) {
        move(1, 0, walk_step);
    }
    if (ctx->keystate[SDL_SCANCODE_S]) {
        move(-1, 0, walk_step);
    }
    if (ctx->keystate[SDL_SCANCODE_D]) {
        move(1, 1, walk_step);
    }
    if (ctx->keystate[SDL_SCANCODE_A]) {
        move(1, -1, walk_step);
    }

}

static void draw()
{
    // floor
    painter_rect_fill(window->rend, GRAY, (SDL_Rect){0, window->height / 2, window->width, window->height / 2});

    // walls
    for (int x = 0; x < window->width; x++) {
        float ray_angle = (pa - fov / 2) + (float)x / (float)window->width * fov;
        float distance_to_wall = 0;
        bool hit_wall = false;
        
        float eye_x = sinf(ray_angle);
        float eye_y = cosf(ray_angle);

        while (!hit_wall && distance_to_wall < depth) {
            distance_to_wall += cast_step;
            int test_x = px + eye_x * distance_to_wall;
            int test_y = py + eye_y * distance_to_wall;

            // ray is out of bounds
            if (test_x < 0 || test_x >= map_width || test_y < 0 || test_y >= map_height) {
                distance_to_wall = depth;
                hit_wall = true;
            }
            // ray is in bounds
            else {
                // cell is a wall
                if (map[test_y][test_x] == wall_char)
                    hit_wall = true;
                // cell is something else
                else {

                }
            }
        }
        int ceiling = window->height / 2.0 - window->height / distance_to_wall;
        int floor = window->height - ceiling;
        unsigned char s = fmax(fmin((int)(1.0f / distance_to_wall * 255 * 3), 255), 0);
        // draw walls
        painter_rect_fill(window->rend, (SDL_Color){s, s, s, 255}, (SDL_Rect){x, ceiling, 1, floor - ceiling});
    }
}

/**
 * Initialization
 */

static void setup()
{
    Event *keys_event = event_new(&call_keys, keys);
    array_push(ctx->events, keys_event);
    Event *draw_event = event_new(&call_draw, draw);
    array_push(ctx->events, draw_event);
}

void first()
{
    window = window_new("Ceng", 640, 480);
    ctx    = context_new(window, 60);

    setup();

    context_run(ctx);

    // tear down
    context_free(ctx);
    window_free(window);
}
