#ifndef BLOCK_H
#define BLOCK_H

#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 8.0f

typedef enum {
    BLOCK_AIR,
    BLOCK_SAND,
    BLOCK_WATER,
    BLOCK_WOOD,
} BlockType_t;

typedef union {
    void* air;
    void* sand;

    struct {
        int8_t direction;
    } water;

    void* wood;
} BlockData_t;

typedef struct {
    BlockType_t type;
    BlockData_t data;    
} Block_t;

Block_t airBlock();
Block_t sandBlock();
Block_t waterBlock();
Block_t woodBlock();

#endif
