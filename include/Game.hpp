#ifndef _GAME_HPP_
#define _GAME_HPP_

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