#include "Header.hpp"
#include "Mix.hpp"
#include "Mario.hpp"

Mario::Mario(){
    scale = 4;
    src = {0, 72, 18, 18};
    dst = {72, 576, 72, 72};
    Animation = IDLE;
    PowerUp = NONE;
}

Mario::Mario(int p_scale){
    scale = p_scale;
    src = {0, 72, 18, 18};
    dst = {0, 0, 18 * scale, 18 * scale};
    Animation = IDLE;
    PowerUp = NONE;
}

void Mario::Update(Input input, SDL_Renderer* renderer, SDL_Texture* texture, Mix* mix){
    //Check for PoweUps:
    if(input.SELECT && _DebugSELECTCoolDown <= 0){
        _DebugSELECTCoolDown = 5;
        if(PowerUp == NONE){
            PowerUp = BIG;
        }else if(PowerUp == BIG){
            PowerUp = FIRE;
        }else if(PowerUp == FIRE){
            PowerUp = NONE;
        }
    }else if(input.SELECT){
        _DebugSELECTCoolDown--;
    }

    //Gravity
    velocity.y = 15;

    //change position based on input
    if(input.LEFT){
        velocity.x = -10;
        Direction = LEFT;
    }
    if(input.RIGHT){
        velocity.x = 10;
        Direction = RIGHT;
    }
    if(input.B){
        if(Direction == RIGHT){
            velocity.x += 5;
        }else if(Direction == LEFT){
            velocity.x += -5;
        }
    }
    if(!input.RIGHT && !input.LEFT){
        velocity.x = 0;
    }

    if(input.A && on_floor){
        JumpStartPos = dst.y;
        //printf("JUMP!!\n");
        if(PowerUp == NONE){
            mix->PlaySound(JumpSmall);
        }else{
            mix->PlaySound(JumpSuper);
        }
    }else if(input.A){
        if(MaxJumpHeight < 6){
            MaxJumpHeight += 0.15;
        }
    }else if(on_floor){
        JumpStartPos = 3000;
        MaxJumpHeight = 1.0;
    }
    if(dst.y >= JumpStartPos - dst.w * MaxJumpHeight){ //width because marios height will change but his width will allways be small mario's height
        velocity.y = -15;
    }else{
        JumpStartPos = 3000;
    }if(!input.A){
        JumpStartPos = 3000;
    }

    //Update possition based on velocity
    dst.x += velocity.x;
    dst.y += velocity.y;

    //check for collision
    if(dst.x < 0){
        dst.x = 0;
    }
    if(dst.x + dst.w > 1280){
        dst.x = 1280 - dst.w;
    }
    if(dst.y < 0){
        dst.y = 0;
    }
    if(dst.y + dst.h > 720){
        dst.y = 720 - dst.h;
        on_floor = true;
    }else{
        on_floor = false;
    }

    //Update dst and src size based on PowerUp
    switch(PowerUp){
        case NONE:
            src.h = 18;
            dst.h = 18 * scale;
            break;
        case BIG:
            src.h = 36;
            dst.h = 36 * scale;
            break;
        case FIRE:
            src.h = 36;
            dst.h = 36 * scale;
            break;
        default:
            printf("No PowerUp?!?...\n");
            break;
    }

    //check input for animations
    if(velocity.x == 0){
        Animation = IDLE;
    }else{
        Animation = RUN;
    }
    if(!on_floor){
        Animation = JUMP; //keep under run (to make sure JUMP overrides RUN)
    }
    if(input.DOWN && (PowerUp == BIG || PowerUp == FIRE)){
        Animation = DUCK;
    }
    if(input.B && PowerUp == FIRE && B_Held > 0){
        B_Held--;
        if(velocity.x == 0){
            Animation = THROW;
        }else{
            Animation = THROW_RUN;
        }
        if(!on_floor){
            Animation = THROW_JUMP;
        }
    }else if(!input.B){
        B_Held = 10;
    }

    //Animate:
    switch(Animation){
        case IDLE:  //done
            switch(PowerUp){
                case NONE:
                    src.x = 0;
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 0;
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 0;
                    src.y = 36;
                    break;
            }
            break;
        case RUN:   //Perfect
            int rn_mtlpr;
            if(input.B){
                rn_mtlpr = 5;
            }else{
                rn_mtlpr = 10;
            }
            if(frame > 2.9 * rn_mtlpr){
                frame = 0;
            }
            switch(PowerUp){
                case NONE:
                    src.x = 72 + 18 * (frame / rn_mtlpr);
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 72 + 18 * (frame / rn_mtlpr);
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 72 + 18 * (frame / rn_mtlpr);
                    src.y = 36;
                    break;
            }
            frame++;
            break;
        case JUMP:  //done
            switch(PowerUp){
                case NONE:
                    src.x = 36;
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 36;
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 36;
                    src.y = 36;
                    break;
            }
            break;
        case STOP:  //done
            switch(PowerUp){
                case NONE:
                    src.x = 18;
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 18;
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 18;
                    src.y = 36;
                    break;
            }
            break;
        case DUCK:  //done
            switch(PowerUp){
                case NONE:
                    src.x = 0;
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 54;
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 54;
                    src.y = 36;
                    break;
            }
            break;
        case CLIMB: //done
        if(frame > 1){
            frame = 0;
        }
            switch(PowerUp){
                case NONE:
                    src.x = 126 + 18 * frame;
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 126 + 18 * frame;
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 126 + 18 * frame;
                    src.y = 36;
                    break;
            }
            frame++;
            break;
        case SWIM:  //done
            if(frame > 5){
                frame = 0;
            }
            switch(PowerUp){
                case NONE:
                    src.x = 162 + 18 * frame;
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 162 + 18 * frame;
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 162 + 18 * frame;
                    src.y = 36;
                    break;
            }
            frame++;
            break;
        case THROW: //done
            switch(PowerUp){
                case NONE:
                    src.x = 0;
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 0;
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 270;
                    src.y = 36;
                    break;
            }
            break;
        case THROW_RUN:   //Like RUN
            int fr_rn_mtlpr;
            fr_rn_mtlpr = 5;
            if(frame > 2.9 * fr_rn_mtlpr){
                frame = 0;
            }
            switch(PowerUp){
                case NONE:
                    src.x = 72 + 18 * (frame / fr_rn_mtlpr);
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 72 + 18 * (frame / fr_rn_mtlpr);
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 306 + 18 * (frame / fr_rn_mtlpr);
                    src.y = 36;
                    break;
            }
            frame++;
            break;
        case THROW_JUMP:  //done
            switch(PowerUp){
                case NONE:
                    src.x = 36;
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 36;
                    src.y = 0;
                    break;
                case FIRE:
                    src.x = 288;
                    src.y = 36;
                    break;
            }
            break;
        case DIE:   //done
            switch(PowerUp){
                case NONE:
                    src.x = 54;
                    src.y = 72;
                    break;
                case BIG:
                    src.x = 0;
                    src.y = 72;
                    break;
                case FIRE:
                    src.x = 0;
                    src.y = 0;
                    break;
            }
            break;
        default:
            printf("ERROR: No Animation! %s\n", SDL_GetError());
            break;
    }

    if(Direction == LEFT){
        SDL_RenderCopyEx(renderer, texture, &src, &dst, 0, NULL, SDL_FLIP_HORIZONTAL);
    }else{
        SDL_RenderCopy(renderer, texture, &src, &dst);
    }
}