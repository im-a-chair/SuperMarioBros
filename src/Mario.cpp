#include "Mario.hpp"

#include <stdio.h>
#include <SDL2/SDL.h>

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
    if(input.LEFT){
        Velocity.x += -10;
    }
    if(input.RIGHT){
        Velocity.x += 10;
    }
    if(input.A){}
    if(input.B){}
    if(input.DOWN){}    //Make sure to reduce hitbox

    //Check for collision
        //With border
    if(dst.y < 0){
        dst.y = 0;
    }else if(dst.y > Engine::Screen.h - dst.h){
        dst.y =  Engine::Screen.h - dst.h;
    }
    if(dst.x < 0){
        dst.x = 0;
    }else if(dst.x > Engine::Screen.w - dst.w){
        dst.x =  Engine::Screen.w - dst.w;
    }

    //Update State and Animation


    //Animate

    
    //Render
    SDL_RenderCopy(renderer, IMG::MarioTex, &src, &dst);
}
