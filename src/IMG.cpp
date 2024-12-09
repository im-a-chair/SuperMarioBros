#include "IMG.hpp"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include "Engine.hpp"

IMG::IMG(SDL_Renderer* renderer, int scale){
    if(IMG_Init(IMG_INIT_PNG) < 0){
        printf("ERROR: IMG_Init Failed; %s\n", SDL_GetError());
    }

    Scale = scale;

    //char* t_basepath = SDL_GetBasePath();//Engine::BasePath;

    //Load Mario's Textures:
    char* t_path = SDL_GetBasePath();// = t_basepath;
    strcat(t_path, (char*)"res/Textures/mario.png");
    MarioTex = IMG_LoadTexture(renderer, t_path);
    if(MarioTex == NULL){
        printf("ERROR: IMG_LoadTexture Failed on Mario; %s\n", IMG_GetError());
    }

    //Load the Tile Textures:
    t_path = SDL_GetBasePath();// = t_basepath;
    strcat(t_path, (char*)(char*)"res/Textures/blocks.png");
    BlockTex = IMG_LoadTexture(renderer, t_path);
    if(BlockTex == NULL){
        printf("ERROR: IMG_LoadTexture Failed on Block; %s\n", IMG_GetError());
    }

    //Load the Enemy Textures:
    t_path = SDL_GetBasePath();// = t_basepath;
    strcat(t_path, (char*)(char*)"res/Textures/enemies.png");
    EnemyTex = IMG_LoadTexture(renderer, t_path);
    if(EnemyTex == NULL){
        printf("ERROR: IMG_LoadTexture Failed on Enemy; %s\n", IMG_GetError());
    }
}

IMG::~IMG(){
    SDL_DestroyTexture(MarioTex);
    SDL_DestroyTexture(BlockTex);
    SDL_DestroyTexture(EnemyTex);
    IMG_Quit();
}