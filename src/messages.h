#ifndef MESSAGES_H
#define MESSAGES_H

#include <SDL2/SDL.h>
#include <string>
#include <cstring>
#include <iostream>
#include "game.h"

class Game;

void ShowStartMenu(Game& game);
void ShowPauseMenu(Game& game);

#endif