#pragma once
#ifndef _SUPER_MARIO_BROS_MARIO_HPP_
#define _SUPER_MARIO_BROS_MARIO_HPP_

#include <SDL2/SDL.h>
#include "Engine.hpp"
#include "IMG.hpp"

class Mario{
public:
    Mario(int scale);
    ~Mario();
    void Update(SDL_Renderer* renderer, Engine::Input input, IMG img);
private:
    SDL_Point Velocity;
    SDL_Rect src;
    SDL_Rect dst;
    enum Animation{
        IDLE,
        RUN,
        JUMP
    }Animation;
    enum PowerUp{
        SMALL,
        BIG,
        FIRE
    }PowerUp;
};

#endif