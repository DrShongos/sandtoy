#include "user.h"
#include "block.h"
#include "raylib.h"
#include "world.h"
#include "math.h"
#include <stdlib.h>

WorldPosition_t getClickWorldPosition()
{
    float x = floorf(GetMouseX() / BLOCK_SIZE);
    float y = floorf(GetMouseY() / BLOCK_SIZE);

    WorldPosition_t worldPos;
    worldPos.x = (uint32_t)x;
    worldPos.y = (uint32_t)y;

    return worldPos;
}

void handleInput(User_t *user, World_t* world)
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        WorldPosition_t pos = getClickWorldPosition();            
        if (user->currentBlock.type == BLOCK_AIR) {
            replaceBlock(world, pos.x, pos.y, user->currentBlock);
        } else {
            Block_t* toReplace = getBlockAt(world, pos.x, pos.y);
            if (toReplace != NULL && toReplace->type == BLOCK_AIR)
                replaceBlock(world, pos.x, pos.y, user->currentBlock);
        }       
    }

    if (IsKeyPressed(KEY_ZERO)) 
        user->currentBlock = airBlock();

    if (IsKeyPressed(KEY_ONE))
        user->currentBlock = sandBlock();

    if (IsKeyPressed(KEY_TWO))
        user->currentBlock = waterBlock();
    
    if (IsKeyPressed(KEY_THREE))
        user->currentBlock = woodBlock();
}
