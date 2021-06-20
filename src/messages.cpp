#include "messages.h"

void ShowPauseMenu(Game& game){
  const SDL_MessageBoxButtonData pause_buttons[] = {
    {0, 0, "Resume Game"}
  };

  std::string msg = "Take a breath \nCurrent Score: " + std::to_string(game.GetScore()) +"\nCurrent Size: " + std::to_string(game.GetSize());
  const SDL_MessageBoxData pause_data = {
    SDL_MESSAGEBOX_INFORMATION,
    NULL,
    "Kronos Snake",
    msg.c_str(),
    SDL_arraysize(pause_buttons),
    pause_buttons,
    NULL
  };

  int button_pressed;
  if (SDL_ShowMessageBox(&pause_data, &button_pressed) < 0){
    std::cout << "Error display pause message box\n";
    return;
  }
  if (button_pressed == 0){
    // resume game
    game.SetPause(false);
  }
}

void ShowStartMenu(Game& game){
  const SDL_MessageBoxButtonData menu_buttons[] = {
    { 0, 0, "High Scores"},
    { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Play"},
    { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "Quit"}
  };

  const SDL_MessageBoxData menu_data = {
    SDL_MESSAGEBOX_INFORMATION, 
    NULL,
    "Kronos Snake",
    "Welcome! Please select what to do next",
    SDL_arraysize(menu_buttons),
    menu_buttons,
    NULL
  };

  int button_pressed;
  if (SDL_ShowMessageBox(&menu_data, &button_pressed)<0) {
    SDL_Log("Error displaying Menu");
    return;
  }

  //std::cout << button_pressed << std::endl;
  if (button_pressed == 0){
    //high scores
  
  }
  else if(button_pressed == 1){
    // Play
    game.SetPause(false);
    game.SetRunning(true);
    game.SetStart(false);
  }
  else if(button_pressed == 2){
    // quit
    game.SetRunning(false);
  }

}