#include "Mario.hpp"

#include <stdio.h>
#include <SDL2/SDL.h>

#include "IMG.hpp"

Mario::Mario(int scale){
    Velocity = {0, 0};
    src = {0, 72, 18, 18};
    dst = {300, 300, 18 * scale, 18 * scale};
    Animation = IDLE;
    PowerUp = SMALL;
}

Mario::~Mario(){}

void Mario::Update(SDL_Renderer* renderer, Engine::Input input, IMG img){
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
    SDL_RenderCopy(renderer, img.MarioTex, &src, &dst);
}
