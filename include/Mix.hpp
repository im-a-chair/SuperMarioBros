#pragma once
#ifndef _MIX_HPP_
#define _MIX_HPP_
#include <SDL2/SDL_mixer.h>

typedef enum Sound{
    OneUp,
    BowserFall,
    BowserFire,
    BreakBlock,
    Bump,
    Coin,
    FireBall,
    FireWorks,
    FlagPole,
    GameOver,
    JumpSmall,
    JumpSuper,
    Kick,
    MarioDies,
    Pause,
    Pipe,
    PowerUpApears,
    PowerUp,
    StageClear,
    Stomp,
    Vine,
    Warning,
    WorldClear
}sound;
typedef enum Music{
    Castle,
    End,
    Flag,
    GameOver_MUS,
    Over,
    StarManCloud,
    UnderWorld,
    Water
}music;

class Mix{
public:
    Mix();
    ~Mix();
    void PlaySound(Sound p_sound);
    void PlayMusic(Music p_music);
    void UpdateMusic(Environment environment);
private:
    struct sounds{
        Mix_Chunk* OneUp;
        Mix_Chunk* BowserFall;
        Mix_Chunk* BowserFire;
        Mix_Chunk* BreakBlock;
        Mix_Chunk* Bump;
        Mix_Chunk* Coin;
        Mix_Chunk* FireBall;
        Mix_Chunk* FireWorks;
        Mix_Chunk* FlagPole;
        Mix_Chunk* GameOver;
        Mix_Chunk* JumpSmall;
        Mix_Chunk* JumpSuper;
        Mix_Chunk* Kick;
        Mix_Chunk* MarioDies;
        Mix_Chunk* Pause;
        Mix_Chunk* Pipe;
        Mix_Chunk* PowerUpApears;
        Mix_Chunk* PowerUp;
        Mix_Chunk* StageClear;
        Mix_Chunk* Stomp;
        Mix_Chunk* Vine;
        Mix_Chunk* Warning;
        Mix_Chunk* WorldClear;
    }sounds;
    struct music{
        Mix_Music* Castle;
        Mix_Music* End;
        Mix_Music* Flag;
        Mix_Music* GameOver;
        Mix_Music* Over;
        Mix_Music* StarManCloud;
        Mix_Music* UnderWorld;
        Mix_Music* Water;
    }music;
};

#endif