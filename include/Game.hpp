#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SDL2/SDL.h>

class Game{
public:
    Game();
    ~Game();
    void Loop();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif