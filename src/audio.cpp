#include "audio.h"

Audio::Audio(std::string filename){
  SDL_LoadWAV(filename, &spec, &buffer, &length);
  dev_id = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
}

Audio::~Audio()
{
  SDL_CloseAudioDevice(dev_id);
  SDL_FreeWAV(buffer);
}

void Audio::play(){
  SDL_QueueAudio(dev_id, buffer, length);
  SDL_PauseAudio(dev_id, 0);
}