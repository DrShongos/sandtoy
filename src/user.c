#include "user.h"
#include "raylib.h"
#include "world.h"
#include "math.h"

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
        replaceBlock(world, pos.x, pos.y, user->currentBlock);
    }

    if (IsKeyPressed(KEY_ZERO)) 
        user->currentBlock = BLOCK_AIR;

    if (IsKeyPressed(KEY_ONE))
        user->currentBlock = BLOCK_SAND;

    // Second key is reserved for water
    
    if (IsKeyPressed(KEY_THREE))
        user->currentBlock = BLOCK_WOOD;
}
