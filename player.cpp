#include "player.h"
#include "laser.h"
#include <SDL2/SDL_image.h>

Player::Player() {
 // image = IMG_LoadTexture(renderer, "./image.png");
 // if (image == nullptr) {
 //   std::cerr << "IMG_LoadTexture Error: " << SDL_GetError() << "\n";
 // }

 // SDL_QueryTexture(image, nullptr, nullptr, &w, &h);
//  SDL_RenderClear(renderer);
  rect = {290, 430, 50, 50}; // x, y, w, h
//  SDL_RenderCopy(renderer, image, nullptr, &rect);
//  SDL_RenderPresent(renderer);
  std::cout << rect.x << "\n";
}

// Player::~Player() {
//   SDL_DestroyTexture(image);
// }

void Player::update(int direction) {
  // dx += direction * (10.0 * delta_time);
  rect.x += direction * 5;
  if (rect.x <= 0)
    rect.x = 0;
  else if (rect.x >= 630) {
    rect.x = 630;
  }
}

void Player::draw(SDL_Renderer *renderer) {
 //  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
   SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
   SDL_RenderFillRect(renderer, &rect);
  // rect = {x, y, w, h}; // x, y, w, h
 // SDL_RenderCopy(this->renderer, image, nullptr, &rect);
}

int Player::getx() { return rect.x; }

int Player::gety() { return rect.y; }

int Player::getw() { return rect.w; }

int Player::geth() { return rect.h; }
