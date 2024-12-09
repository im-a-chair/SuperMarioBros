#pragma once
#ifndef _SUPER_MARIO_BROS_GAME_HPP_
#define _SUPER_MARIO_BROS_GAME_HPP_

#include <SDL2/SDL.h>

#include "Engine.hpp"

class Game{
public:
    Game();
    ~Game();
    void Loop();
private:
    bool Paused;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Engine::Input input;
};

#endif