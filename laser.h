#ifndef LASER_H
#define LASER_H
#include <SDL2/SDL.h>
#include "player.h"
#include <iostream>
#include "entity.h"

class Laser : Entity {
 public:
  Laser(int x, int y);
  ~Laser() = default;

  void update();
  void draw(SDL_Renderer *renderer);
  
  int getx() override;
  int gety() override;
  int geth() override;
  int getw() override;

  SDL_Rect rect;
  // SDL_Texture *image;
};

#endif // LASER_H
