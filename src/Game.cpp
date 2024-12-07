#include <stdio.h>
#include <SDL2/SDL.h>
#include "Header.hpp"
#include "Game.hpp"

#include "IMG.hpp"
#include "Mix.hpp"
#include "Mario.hpp"

Game::Game(){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0){
        printf("ERROR: SDL_Init Failed; %s\n", SDL_GetError());
    }
    window = SDL_CreateWindow("Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    if(window == NULL){
        printf("ERROR: SDL_CreateWindow Failed; %s\n", SDL_GetError());
    }
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

void Game::Loop(){
    IMG img(renderer);
    Mix mix;
    Mario mario;
    Environment environment = GROUND;

    bool running = true;
    SDL_Event event;
    Input Input;
    while(running){
        //Input
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_UP:
                            Input.UP = true;
                            break;
                        case SDLK_DOWN:
                            Input.DOWN = true;
                            break;
                        case SDLK_LEFT:
                            Input.LEFT = true;
                            break;
                        case SDLK_RIGHT:
                            Input.RIGHT = true;
                            break;
                        case SDLK_z:
                            Input.B = true;
                            break;
                        case SDLK_x:
                            Input.A = true;
                            break;
                        case SDLK_RETURN:
                            Input.START = true;
                            paused = !paused;
                            break;
                        case SDLK_LSHIFT:
                            Input.SELECT = true;
                            break;
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch(event.key.keysym.sym){
                        case SDLK_UP:
                            Input.UP = false;
                            break;
                        case SDLK_DOWN:
                            Input.DOWN = false;
                            break;
                        case SDLK_LEFT:
                            Input.LEFT = false;
                            break;
                        case SDLK_RIGHT:
                            Input.RIGHT = false;
                            break;
                        case SDLK_z:
                            Input.B = false;
                            break;
                        case SDLK_x:
                            Input.A = false;
                            break;
                        case SDLK_RETURN:
                            Input.START = false;
                            break;
                        case SDLK_LSHIFT:
                            Input.SELECT = false;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        if(!paused){
            SDL_RenderClear(renderer);

            //Update
            mario.Update(Input, renderer, img.GetMarioTex(), &mix);

            SDL_RenderPresent(renderer);

            SDL_Delay(50);

            mix.UpdateMusic(environment);
        }
    }
}