#ifndef USER_H
#define USER_H

#include "raylib.h"
#include <stdint.h>

typedef struct {
    uint32_t x;
    uint32_t y;
} WorldPosition_t;

WorldPosition_t getClickWorldPosition();

#endif
