#include <stdio.h>
#include "Header.hpp"
#include "IMG.hpp"

IMG::IMG(SDL_Renderer* renderer){
    if(IMG_Init(IMG_INIT_PNG) < 0){
        printf("ERROR: IMG_Init Failed; %s\n", SDL_GetError());
    }
    
    char* BasePath = SDL_GetBasePath();
    char* B_Path = strcat(BasePath, "res/Textures/blocks.png");
    BasePath = SDL_GetBasePath();
    char* E_Path = strcat(BasePath, "res/Textures/enemies.png");
    BasePath = SDL_GetBasePath();
    char* M_Path = strcat(BasePath, "res/Textures/mario.png");
    BasePath = SDL_GetBasePath();

    blocks_tex = IMG_LoadTexture(renderer, B_Path);
    enemies_tex = IMG_LoadTexture(renderer, E_Path);
    mario_tex = IMG_LoadTexture(renderer, M_Path);
    if(blocks_tex == NULL || enemies_tex == NULL || mario_tex == NULL){
        printf("ERROR: IMG_LoadTexture Failed; %s\n", SDL_GetError());
    }
}

IMG::~IMG(){
    SDL_DestroyTexture(blocks_tex);
    SDL_DestroyTexture(enemies_tex);
    SDL_DestroyTexture(mario_tex);
    IMG_Quit();
}

SDL_Texture* IMG::GetBlocksTex(){
    return blocks_tex;
}
SDL_Texture* IMG::GetEnemiesTex(){
    return enemies_tex;
}
SDL_Texture* IMG::GetMarioTex(){
    return mario_tex;
}