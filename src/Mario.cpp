#include <stdio.h>
#include <SDL2/SDL.h>

#include "Mario.hpp"
#include "Engine.hpp"
#include "IMG.hpp"

Mario::Mario(){
    Velocity = {0, 0};
    src = {0, 0, 18, 18};
    dst = {0, 0, 18 * IMG::Scale, 18 * IMG::Scale};
    Animation = IDLE;
    PowerUp = SMALL;
}

Mario::~Mario(){}

void Mario::Update(SDL_Renderer* renderer, Engine::Input input){
    //Set Constant Movements
        //Gravity:
    Velocity.y = Engine::Gravity;   //TODO: when underwater, make gravity less

    //Apply Input Movement
    if(input.LEFT){}
    if(input.RIGHT){}
    if(input.A){}
    if(input.B){}
    if(input.DOWN){}    //Make sure to reduce hitbox

    //Update State and Animation


    //Animate

    
    //Render
    SDL_RenderCopy(renderer, IMG::MarioTex, &src, &dst);
}
