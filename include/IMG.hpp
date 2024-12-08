#ifndef _IMG_HPP_
#define _IMG_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace IMG{
    int Scale;
    SDL_Texture* MarioTex;
    SDL_Texture* BlockTex;
    SDL_Texture* EnemyTex;

    void Init_IMG();
    void Quit_IMG();
}

#endif