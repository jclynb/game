#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <iostream>
#include "entity.h"

class Enemy : Entity {
 public:
  Enemy();
  ~Enemy() = default;

  void update();
  void draw(SDL_Renderer *renderer);

  int getx() override;
  int gety() override;
  int geth() override;
  int getw() override;
  
  SDL_Rect rect;
};

#endif // ENEMY_H
