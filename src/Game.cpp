#include <stdio.h>
#include <SDL2/SDL.h>

#include "Game.hpp"

Game::Game(){
    //initialize:
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0){
        printf("ERROR: SDL_Init Failed; %s\n", SDL_GetError());
    }

    //Make Window:
    window = SDL_CreateWindow("Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    if(window == NULL){
        printf("ERROR: SDL_CreateWindow Failed; %s\n", SDL_GetError());
    }

    //Make Renderer:
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("ERROR: SDL_CreateRenderer Failed; %s\n", SDL_GetError());
    }
}

Game::~Game(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::Loop(){}
