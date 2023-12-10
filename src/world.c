#include "world.h"
#include "raylib.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

World_t createWorld(uint32_t width, uint32_t height)
{
    World_t world;
    Block_t** blocks = (Block_t**)malloc(height * sizeof(Block_t*));
    
    for (int i = 0; i < height; i++) {
        blocks[i] = (Block_t*)malloc(width * sizeof(Block_t));
        for (int j = 0; j < width; j++) {
            blocks[i][j] = BLOCK_AIR;
        }
    }

    world.blocks = blocks;
    world.width = width;
    world.height = height;
    return world;
}

void deleteWorld(World_t *world)
{
    world->height = 0;
    world->width = 0;
    free(world->blocks);
}


Block_t* getBlockAt(World_t *world, uint32_t x, uint32_t y)
{
    // Check if the position will be within world's bounds
    if (x > world->width - 1 || y > world->height - 1) {
        return NULL;
    }

    return &world->blocks[y][x];
}

static bool isBlockEmpty(Block_t* block) 
{
    return (block != NULL && *block == BLOCK_AIR);
}

void updateWorld(World_t *world)
{
    for (int y = world->height - 1; y >= 0; y--) {
        for (int x = 0; x < world->width; x++) {
            
            Block_t* block = getBlockAt(world, x, y);

            switch (*block) {
                case BLOCK_SAND: {
                    Block_t* bottom = getBlockAt(world, x, y + 1);
                    Block_t* left = getBlockAt(world, x - 1, y);
                    Block_t* right = getBlockAt(world, x + 1, y);
                    Block_t* bottomLeft = getBlockAt(world, x - 1, y + 1);
                    Block_t* bottomRight = getBlockAt(world, x + 1, y + 1);

                    if (isBlockEmpty(bottom)) { 
                        swapBlocks(block, bottom);
                        break;
                    }

                    // Block sides are checked on the same y to prevent leaking through diagonal lines
                    if (isBlockEmpty(left) && isBlockEmpty(bottomLeft)) {
                        swapBlocks(block, bottomLeft);
                        break;
                    }

                    if (isBlockEmpty(right) && isBlockEmpty(bottomRight)) {
                        swapBlocks(block, bottomRight);
                        break;
                    }

                    break;

                }
                default:
                    break;
            }
        }
    }

}

void replaceBlock(World_t* world, uint32_t x, uint32_t y, Block_t newBlock)
{
    Block_t* block = getBlockAt(world, x, y);
    if (block == NULL)
        return;

    *block = newBlock;
}

void swapBlocks(Block_t *block, Block_t *other)
{
    Block_t tmp = *block;
    *block = *other;
    *other = tmp;
}

static Color getBlockColor(Block_t block)
{
    // TODO: Find better colors
    switch (block) {
        case BLOCK_SAND:
            return YELLOW;
        case BLOCK_WOOD:
            return BROWN;
        default:
            return BLACK; // Unreachable; World drawing function skips air blocks
    }
}

void drawBlockAt(World_t *world, uint32_t x, uint32_t y)
{
    // Air blocks are skipped to save time
    Block_t* block = getBlockAt(world, x, y);
    if (block == NULL || *block == BLOCK_AIR)
        return;

    Color blockColor = getBlockColor(*block);
    float blockSize = BLOCK_SIZE;

    Rectangle rectangle;
    rectangle.x = (float)x * blockSize;
    rectangle.y = (float)y * blockSize;
    rectangle.width = blockSize;
    rectangle.height = blockSize;

    DrawRectangleRec(rectangle, blockColor);
}
