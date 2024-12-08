#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include <SDL2/SDL.h>

namespace Engine{
    typedef struct Input{
        bool UP;
        bool DOWN;
        bool LEFT;
        bool RIGHT;
        bool A;
        bool B;
        bool START;
        bool SELECT;
    }Input;
    const char* BasePath = SDL_GetBasePath();
    const int Gravity = 0;
}

#endif