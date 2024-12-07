#pragma once
#ifndef _MARIO_HPP_
#define _MARIO_HPP_
#include "Header.hpp"
#include "Mix.hpp"

class Mario{
public:
    Mario();
    Mario(int scale);

    void Update(Input input, SDL_Renderer* renderer, SDL_Texture* texture, Mix* mix);
private:
    int B_Held = 0;
    float MaxJumpHeight = 1;
    int JumpStartPos = 3000;
    bool CanJump = true;
    bool on_floor = false;
    int scale;
    int frame = 0;  // starting at 0
    struct velocity{
        int x = 0;
        int y = 0;
    }velocity;
    SDL_Rect src;
    SDL_Rect dst;
    enum PowerUp{
        NONE,
        BIG,
        FIRE
    }PowerUp;
    enum Animation{
        IDLE,       // 1 frame
        RUN,        // 3 frames
        JUMP,       // 1 frame
        STOP,       // 1 frame
        DUCK,       // 1 frame
        CLIMB,      // 2 frames
        SWIM,       // 5 frames
        THROW,      // 1 frames
        THROW_RUN,  // 3 frames
        THROW_JUMP, // 1 frame 
        DIE         // 1 frame
    }Animation;
    enum Direction{
        LEFT,
        RIGHT
    }Direction;

    int _DebugSELECTCoolDown = 0;
};

#endif