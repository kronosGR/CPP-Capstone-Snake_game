#include "audio.h"

Audio::Audio(){
  // std::cout << std::filesystem::current_path() << std::endl;
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
    std::cout << "SDL_mixer could not initialize. Error: " << Mix_GetError() << std::endl;
  }
  
}

Audio::~Audio()
{
  Mix_FreeChunk(eat);
  Mix_FreeChunk(move);
  Mix_FreeChunk(lost);
  Mix_FreeMusic(music);
  Mix_Quit();
}

void Audio::playMusic(std::string fileName){
  music = Mix_LoadMUS(fileName.c_str());
   if (music == NULL){
    std::cout << "Failed to load music. Error: " << Mix_GetError() << std::endl;
  }
  if (Mix_PlayingMusic() == 0){
    Mix_PlayMusic(music, -1);
  } 
  else {
    if (Mix_PausedMusic() ==1){
      Mix_ResumeMusic();
    }
  }
}

void Audio::playEat(std::string fileName){
  eat = Mix_LoadWAV(fileName.c_str());
  if (eat == NULL){
    std::cout << "Failed to load eat sound effect. Error: " << Mix_GetError() << std::endl;
  }
  Mix_PlayChannel(-1, eat, 0);
}

void Audio::playMove(std::string fileName){
  move = Mix_LoadWAV(fileName.c_str());
  if (move == NULL){
    std::cout << "Failed to load move sound effect. Error: " << Mix_GetError() << std::endl;
  }
  Mix_PlayChannel(1, move, -1);  

}

void Audio::playLost(std::string filename){
  lost = Mix_LoadWAV(filename.c_str());
  if (lost == NULL){
    std::cout << "Failed to load lost sound effect. Error: " << Mix_GetError() << std::endl;
  }
  Mix_PlayChannel(-1, lost, 0);
}

void Audio::pauseMove(){  
  Mix_Pause(1);
}

void Audio::pauseMusic(){
  Mix_PauseMusic();
}