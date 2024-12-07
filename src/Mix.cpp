#include "Header.hpp"
#include "Mix.hpp"

Mix::Mix(){
    if(Mix_Init(MIX_INIT_OGG | MIX_INIT_WAVPACK) < 0){
        printf("ERROR: Mix_Init Failed; %s\n", SDL_GetError());
    }
    if(Mix_OpenAudio(44100, AUDIO_S16LSB, 1, 1024) < 0){
        printf("ERROR: Mix_OpenAudio Failed; %s\n", Mix_GetError());
    }
    char* BasePath = SDL_GetBasePath();

    //Load sounds
    char* JS_S_Path = strcat(BasePath, "res/Audio/SFX/smb_jump-small.wav");
    //printf("%s\n", JS_S_Path);
    sounds.JumpSmall = Mix_LoadWAV(JS_S_Path);
    if(sounds.JumpSmall == NULL){
        printf("ERROR: Mix_LoadWav Failed; %s\n", SDL_GetError());
    }

    //Load Music
    BasePath = SDL_GetBasePath();
    char* Over_M_Path = strcat(BasePath, "res/Audio/Music/SMB_Overworld_Theme.oga");
    music.Over = Mix_LoadMUS(Over_M_Path);
    if(music.Over == NULL){
        printf("ERROR: Mix_LoadMUS Failed; %s\n", SDL_GetError());
    }
}

Mix::~Mix(){
    Mix_FreeChunk(sounds.JumpSmall);
    Mix_FreeMusic(music.Over);
    Mix_Quit();
}

void Mix::PlaySound(Sound p_sound){
    switch(p_sound){
        case JumpSmall:
            Mix_PlayChannel(-1, sounds.JumpSmall, 0);
        default:
            printf("ERROR: Sound not found!");
    }
}

void Mix::PlayMusic(Music p_music){
    switch(p_music){
        case Over:
            Mix_PlayMusic(music.Over, 0);
        default:
            printf("ERROR: Music not found!");
    }
}

void Mix::UpdateMusic(Environment environment){
    if(!Mix_PlayingMusic){
        switch (environment){
            case GROUND:
                Mix_PlayMusic(music.Over, 0);
                break;
            default:
                break;
        }
    }
}
