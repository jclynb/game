#include <SDL2/SDL.h>
#include "application.h"
#include "player.h"
#include "laser.h"
#include "enemy.h"

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 480
#define enemy_count 3

Application::Application() {
  // // Initialize SDL
  // if (SDL_Init(SDL_INIT_VIDEO) != 0) {
  //   std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
  // }

  // // Initalize SDL_Image
  // if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
  //     std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
  //   }

  // Create window
  window = SDL_CreateWindow(
                              "Game Window",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN
                              );
  if (window == NULL) {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
    return;
  }

  // Create Renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    fprintf(stderr, "failed to get surface from window: %s\n", SDL_GetError());
    return;
  }

  // Initalize Game Objects
  Player player;
  direction = 0;
  firing = false;

  lasers = {};
  enemies = {};
  for(int i = 0; i < enemy_count; i++) {
    Enemy enemy;
    enemies.push_back(enemy);
  }
  // enemyTree = SegmentTree<Enemy>(enemies);
  // laserTree = SegmentTree<Laser>(lasers);
}

Application::~Application() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Application::loop() {
  bool running = true;
  while(running) {
    while(SDL_PollEvent(&event) > 0) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        handleKeyDown(&event.key);
        break;
      case SDL_KEYUP:
        handleKeyUp(&event.key);
        break;
      } break;
    }
    update();
    checkcollisions();
    draw();
    if (enemies.empty()) {
      // display "you win" message
    }
  }
}

void Application::handleKeyDown(SDL_KeyboardEvent *event) {
  if (event->keysym.sym == SDLK_LEFT) {
    direction = -1;
  }
  
  else if (event->keysym.sym == SDLK_RIGHT) {
    direction = 1;
  }
  
  else if (event->keysym.sym == SDLK_SPACE) {
    firing = true;
    int x = (player.getx() + (player.getw() / 2) - 5);
    int y = player.gety();
    Laser laser(x,y);
    lasers.push_back(laser);
  }
}

void Application::handleKeyUp(SDL_KeyboardEvent *event) {
  if (event->keysym.sym == SDLK_LEFT) {
    direction = 0;
  }

  else if (event->keysym.sym == SDLK_RIGHT) {
    direction = 0;
  }

  else if (event->keysym.sym == SDLK_SPACE) {
    firing = false;
  }
}

void Application::update() {
  player.update(direction);

  for(int i = 0; i < lasers.size(); i++) {
    if (lasers[i].rect.y < 0) {
      lasers.erase(lasers.begin() + i);
      i--;
    } else {
      lasers[i].update();
      // LaserEnemyCollisions(lasers[i]);
    }
  }

  for(int i = 0; i < enemies.size(); i++) {
    enemies[i].update();
    // EnemyEnemyCollisions(enemies[i]);
  }
  // update enemy tree
  // enemyTree = SegmentTree<Enemy>(enemies);
}

void Application::checkcollisions() {
  for (int i = 0; i < lasers.size(); i++) {
    for (int j = 0; j < enemies.size(); j++) {
      if (intersection(lasers[i], enemies[i])) {
        enemies.erase(enemies.begin() + j);
        lasers.erase(lasers.begin() + i);
        j--;
        i--;
        break;
      }
    }
  }
}

bool Application::intersection(Laser &r1, Enemy &r2) {
  SDL_Rect *r1p = &r1.rect;
  SDL_Rect *r2p = &r2.rect;
  return !(r2p->x > (r1p->x + r1p->w) ||
           (r2p->x + r2p->w) < r1p->x ||
           r2p->y > (r1p->y + r1p->h) ||
           (r2p->y + r2p->h) < r1p->y);
}

void Application::draw() {
  // Clear Screen
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // Draw objects
  player.draw(renderer);

  for(int i = 0; i < lasers.size(); i++) {
    lasers[i].draw(renderer);
  }

  for(int i = 0; i < enemies.size(); i++) {
    enemies[i].draw(renderer);
  }

  // Update Screen
  SDL_RenderPresent(renderer);

  // Calculates to 60 fps
  SDL_Delay(1000 / 60);
}








// void Application::LaserEnemyCollisions(Laser &laser) {
//   std::vector<SDL_Rect> collidedEnemies = enemyTree.queryTree(laser.lrect);
//   for (int i = 0; i < collidedEnemies.size(); i++) {
//     enemies.erase(std::remove(enemies.begin(), enemies.end(), collidedEnemies[i]), enemies.end());
//     lasers.erase(std::remove(lasers.begin(), lasers.end(), laser), lasers.end());
//   }
// }

// void Application::EnemyEnemyCollisions(Enemy &enemy) {
//   // query enemy tree for enemies that intersect with this enemy
//   std::vector<SDL_Rect> collidedEnemies = enemyTree.queryTree(enemy.rect);
//   for (int j = 0; j < collidedEnemies.size(); j++) {
//     if (enemy.rect != &collidedEnemies[j]) {
//       // move enemy away from collided enemy
//       if (enemy.rect.x < collidedEnemies[j].x) {
//         enemy.rect.x--;
//       }
//       else if (enemy.rect.x > collidedEnemies[j].x) {
//         enemy.rect.x++;
//       }
//       if (enemy.rect.y < collidedEnemies[j].y) {
//         enemy.rect.y--;
//       }
//       else if (enemy.rect.y > collidedEnemies[j].y) {
//         enemy.rect.y++;
//       }
//     }
//   }
// }  
