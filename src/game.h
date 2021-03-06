#ifndef GAME_H
#define GAME_H

#include <random>
#include <mutex>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "audio.h"

// forward declaration to avoid header recursion
class Controller;

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  void SetPause(bool _paused);
  bool GetPause();
  void SetRunning(bool _running);
  void SetStart(bool _start);
  void SetBorder(bool _border);
  bool GetBorder();
  

 private:
  Snake snake;
  SDL_Point food;
  Audio audio;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::mutex mtx;

  int score{0};

  void PlaceFood();
  void Update();

  bool start{true};
  bool running{true};
  bool paused{true};
  bool border{false};


};

#endif