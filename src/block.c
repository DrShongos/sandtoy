#include "block.h"

Block_t airBlock()
{
    Block_t block;
    block.type = BLOCK_AIR;
    block.updatedThisFrame = false;
  
    return block;
}

Block_t sandBlock()
{
    Block_t block;
    block.type = BLOCK_SAND;
    block.updatedThisFrame = false;
   
    return block;
}

Block_t waterBlock()
{
    Block_t block;
    block.type = BLOCK_WATER;
    block.data.water.direction = -1;
    block.updatedThisFrame = false;
    
    return block;
}

Block_t woodBlock()
{
    Block_t block;
    block.type = BLOCK_WOOD; 
    block.updatedThisFrame = false;

    return block;
}
