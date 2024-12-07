#pragma once
#ifndef _HEADER_HPP_
#define _HEADER_HPP_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

typedef enum Environment{
    GROUND,
    UNDERGROUND,
    UNDERWATER,
    CASTLE
}Environment;

typedef struct Input{
    bool UP = false;
    bool DOWN = false;
    bool LEFT = false;
    bool RIGHT = false;
    bool A = false;
    bool B = false;
    bool START = false;
    bool SELECT = false;
}Input;

#endif