#include "block.h"

Block_t airBlock()
{
    Block_t block;
    block.type = BLOCK_AIR;
  
    return block;
}

Block_t sandBlock()
{
    Block_t block;
    block.type = BLOCK_SAND;
   
    return block;
}

Block_t waterBlock()
{
    Block_t block;
    block.type = BLOCK_WATER;
    block.data.water.direction = -1;
    
    return block;
}

Block_t woodBlock()
{
    Block_t block;
    block.type = BLOCK_WOOD; 

    return block;
}
