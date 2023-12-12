#ifndef WORLD_H
#define WORLD_H

#include "block.h"
#include <stdint.h>

typedef struct {
    Block_t** blocks;
    uint32_t width;
    uint32_t height;
} World_t;

World_t createWorld(uint32_t width, uint32_t height);
void deleteWorld(World_t* world);
Block_t* getBlockAt(World_t* world, uint32_t x, uint32_t y);

void updateWorld(World_t* world);

void replaceBlock(World_t* world, uint32_t x, uint32_t y, Block_t newBlock);
void swapBlocks(Block_t* block, Block_t* other);

void drawBlockAt(World_t* world, uint32_t x, uint32_t y);

#endif
