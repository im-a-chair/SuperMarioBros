#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Engine.hpp"
#include "IMG.hpp"

void IMG::Init_IMG(SDL_Renderer* renderer){
    if(IMG_Init(IMG_INIT_PNG) < 0){
        printf("ERROR: IMG_Init Failed; %s\n", SDL_GetError());
    }
    const char* t_basepath = Engine::BasePath;

    //Load Mario's Textures:
    char* t_path = strcat("res/Textures/mario.png", t_basepath);
    MarioTex = IMG_LoadTexture(renderer, t_path);
    if(MarioTex == NULL){
        printf("ERROR: IMG_LoadTexture Failed on Mario; %s\n", IMG_GetError());
    }

    //Load the Tile Textures:
    char* t_path = strcat("res/Textures/blocks.png", t_basepath);
    BlockTex = IMG_LoadTexture(renderer, t_path);
    if(BlockTex == NULL){
        printf("ERROR: IMG_LoadTexture Failed on Block; %s\n", IMG_GetError());
    }

    //Load the Enemy Textures:
    char* t_path = strcat("res/Textures/enemies.png", t_basepath);
    EnemyTex = IMG_LoadTexture(renderer, t_path);
    if(EnemyTex == NULL){
        printf("ERROR: IMG_LoadTexture Failed on Enemy; %s\n", IMG_GetError());
    }
}

void IMG::Quit_IMG(){
    SDL_DestroyTexture(MarioTex);
    SDL_DestroyTexture(BlockTex);
    SDL_DestroyTexture(EnemyTex);
    IMG_Quit();
}