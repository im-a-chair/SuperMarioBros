#pragma once
#ifndef _GAME_HPP_
#define _GAME_HPP_
#include <stdio.h>
#include <SDL2/SDL.h>
#include "Header.hpp"

class Game{
public:
    Game();
    ~Game();
    void Loop();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool paused;
};

#endif