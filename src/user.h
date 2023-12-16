#ifndef USER_H
#define USER_H

#include "raylib.h"
#include "world.h"
#include <stdint.h>

#define MAX_RADIUS 10
#define MIN_RADIUS 1

typedef struct {
    uint32_t x;
    uint32_t y;
} WorldPosition_t;

WorldPosition_t getClickWorldPosition();

typedef struct {
    Block_t currentBlock;
    uint8_t placementRadius;
} User_t;

void handleInput(User_t* user, World_t* world);
void handlePlacement(User_t* user, World_t* world, WorldPosition_t* pos);

#endif
