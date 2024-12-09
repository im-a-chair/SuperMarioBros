#pragma once
#ifndef _SUPER_MARIO_BROS_ENGINE_HPP_
#define _SUPER_MARIO_BROS_ENGINE_HPP_

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
    //const char* BasePath = SDL_GetBasePath();   //Multiple definition
    const int Gravity = 0;
    const SDL_Rect Screen = {SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720};
}

#endif