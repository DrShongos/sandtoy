#ifndef USER_H
#define USER_H

#include "raylib.h"
#include "world.h"
#include <stdint.h>

typedef struct {
    uint32_t x;
    uint32_t y;
} WorldPosition_t;

WorldPosition_t getClickWorldPosition();

typedef struct {
    Block_t currentBlock;
} User_t;

void handleInput(User_t* user, World_t* world);

#endif
