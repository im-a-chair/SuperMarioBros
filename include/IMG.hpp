#pragma once
#ifndef _IMG_HPP_
#define _IMG_HPP_

class IMG{
public:
    IMG(SDL_Renderer* renderer);
    ~IMG();

    SDL_Texture* GetBlocksTex();
    SDL_Texture* GetEnemiesTex();
    SDL_Texture* GetMarioTex();
private:
    SDL_Texture* blocks_tex;
    SDL_Texture* enemies_tex;
    SDL_Texture* mario_tex;
};

#endif