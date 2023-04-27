#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "laser.h"
#include "player.h"

// Laser::~Laser() {
//   SDL_DestroyTexture(image);
// }
Laser::Laser(int x, int y) {
  // image = IMG_LoadTexture(renderer, "image.png");
  rect = { x, y, 10, 10 };
  // SDL_QueryTexture(image, nullptr, nullptr, &l_w, &l_h);
}

void Laser::update() {
  rect.y -= 10;
}

void Laser::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
  SDL_RenderFillRect(renderer, &rect);
  // SDL_RenderCopy(renderer, image, nullptr, &laser);
}

int Laser::getx() { return rect.x; }
int Laser::gety() { return rect.y; }
int Laser::getw() { return rect.w; }
int Laser::geth() { return rect.h; }
