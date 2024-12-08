#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Game.hpp"

int main(int Args, char** Argv){
    Game game;
    game.Loop();
    return 0;
}