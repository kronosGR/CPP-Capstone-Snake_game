#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"
#include "snake.h"
#include "messages.h"

// forward declaration to avoid header recursion
class Game;

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, Game &game) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif
