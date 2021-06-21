#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
//#include <filesystem>

class Audio{
  public:
    Audio();
    ~Audio();

    void playMusic(std::string fileName);
    void playEat(std::string fileName);
    void playMove(std::string fileName);
    void playLost(std::string fileName);
    void pauseMusic();
    void pauseMove();

  private:
    Mix_Music *music{NULL};
    Mix_Chunk *eat{NULL};
    Mix_Chunk *move{NULL};
    Mix_Chunk *lost{NULL};

};

#endif