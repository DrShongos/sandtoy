#ifndef BLOCK_H
#define BLOCK_H

#include <stdint.h>

#define BLOCK_SIZE 8.0f

typedef enum {
    BLOCK_AIR,
    BLOCK_SAND,
} Block_t;

typedef struct {
    Block_t** blocks;
    uint32_t width;
    uint32_t height;
} World_t;

World_t createWorld(uint32_t width, uint32_t height);
void deleteWorld(World_t* world);
Block_t* getBlockAt(World_t* world, uint32_t x, uint32_t y);

void updateWorld(World_t* world);

void swapBlocks(Block_t* block, Block_t* other);

void drawBlockAt(World_t* world, uint32_t x, uint32_t y);

#endif
