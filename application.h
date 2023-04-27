#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "player.h"
#include "laser.h"
#include "enemy.h"


class Application {
 public:
  Application();
  ~Application();

  void loop();
  void handleKeyDown(SDL_KeyboardEvent *event);
  void handleKeyUp(SDL_KeyboardEvent *event);
  void update();
  void checkcollisions();
  bool intersection(Laser &r1, Enemy &r2);
  void draw();

 private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;

  Player player;
  int direction;
  bool firing;
  
  std::vector<Laser> lasers;
  std::vector<Enemy> enemies;
};

#endif // APPLICATION_H
