#pragma once
#ifndef _SUPER_MARIO_BROS_IMG_HPP_
#define _SUPER_MARIO_BROS_IMG_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace IMG{
    int Scale;
    SDL_Texture* MarioTex;
    SDL_Texture* BlockTex;
    SDL_Texture* EnemyTex;

    void Init_IMG(SDL_Renderer* renderer);
    void Quit_IMG();
}

#endif