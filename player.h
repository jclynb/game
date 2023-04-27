#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <iostream>
#include "laser.h"
#include "entity.h"

class Player : Entity {
 public:
  Player();
  ~Player() = default;

  void update(int direction);
  void draw(SDL_Renderer *renderer);

  int getx() override;
  int gety() override;
  int geth() override;
  int getw() override;
   SDL_Rect rect;
  // SDL_Texture *image;
  // SDL_Renderer *renderer;
};

#endif // PLAYER_H
