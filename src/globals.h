#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL2/SDL.h>
#include "interface.h"
#include "util/object.h"

// globally accessible Interface object
extern struct Interface interface;
// globally accessible SDL_Window*
extern SDL_Window* window;
// globally accessible SDL_Renderer*
extern SDL_Renderer* renderer;


#endif // GLOBALS_H