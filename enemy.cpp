#include <SDL2/SDL.h>
#include "enemy.h"
#include "laser.h"
#include <cstdlib>
#include <ctime>

Enemy::Enemy() {
  srand(time(NULL));
  rect = {rand() % 680, 0, 30, 30};
}

void Enemy::update() {
  int direction = rand() % 4;
  switch (direction) {
  case 0:
    if (rect.x > 680 || rect.x < 0) {
      rect.x = 0;
    } else {
      rect.x += 5;
    }
      break;
  case 1:
    if (rect.x > 680 || rect.x < 0) {
      rect.x = 0;
    } else {
      rect.x -= 5;
    }
      break;
  case 2:
    if (rect.y > 480 || rect.y < 0) {
      rect.y = 0;
    } else {
      rect.y += 5;
    }
      break;
  case 3:
    if (rect.y > 480 || rect.y < 0) {
      rect.y = 0;
    } else {
      rect.y -= 5;
    }
      break;
  }  
}

void Enemy::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 100, 100, 0, 255);
  SDL_RenderFillRect(renderer, &rect);
}

int Enemy::getx() { return rect.x; }
int Enemy::gety() { return rect.y; }
int Enemy::getw() { return rect.w; }
int Enemy::geth() { return rect.h; }