#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Audio{
  public:
    Audio(std::string filename);
    ~Audio();

    void play();

  private:
    SDL_AudioSpec spec;
    SDL_AudioDeviceID dev_id;
    int length;
    int buffer;
};

#endif