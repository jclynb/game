#ifndef ENTITY
#define ENTITY
#include <SDL2/SDL.h>
class Entity {
public:
    SDL_Rect rect;
    virtual ~Entity() {} // Virtual destructor to allow proper destruction of derived objects
    virtual int getx() = 0;
    virtual int gety() = 0;
    virtual int geth() = 0;
    virtual int getw() = 0;
};

#endif // ENTITY