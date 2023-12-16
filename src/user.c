#include "user.h"
#include "block.h"
#include "raylib.h"
#include "world.h"
#include "math.h"
#include <math.h>
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
        handlePlacement(user, world, &pos);        
    }

    if (IsKeyPressed(KEY_ZERO)) 
        user->currentBlock = airBlock();

    if (IsKeyPressed(KEY_ONE))
        user->currentBlock = sandBlock();

    if (IsKeyPressed(KEY_TWO))
        user->currentBlock = waterBlock();
    
    if (IsKeyPressed(KEY_THREE))
        user->currentBlock = woodBlock();

    float wheel = GetMouseWheelMove();

    if (wheel > 0.0f) {
        user->placementRadius++;
        if (user->placementRadius > MAX_RADIUS)
            user->placementRadius = MAX_RADIUS;
    }

    if (wheel < 0.0f) {
        user->placementRadius--;
        if (user->placementRadius < MIN_RADIUS)
            user->placementRadius = MIN_RADIUS;
    }
}

void handlePlacement(User_t* user, World_t* world, WorldPosition_t* pos)
{
    if (user->placementRadius > 1) {
        uint8_t middle = (uint8_t) floorf((float)(user->placementRadius) / 2.0f);

        for (int y = pos->y + middle; y > pos->y - middle; y--) {
            for (int x = pos->x - middle; x < pos->x + middle; x++) {
                Block_t* toReplace = getBlockAt(world, x, y);
                if (user->currentBlock.type == BLOCK_AIR && toReplace != NULL) {
                    replaceBlock(world, x, y, user->currentBlock);
                } else if (isBlockEmpty(toReplace)) {
                    replaceBlock(world, x, y, user->currentBlock);
                }
            } 
        }
    } else {
        Block_t* toReplace = getBlockAt(world, pos->x, pos->y);
        if (user->currentBlock.type == BLOCK_AIR && toReplace != NULL) {
            replaceBlock(world, pos->x, pos->y, user->currentBlock);
        } else if (isBlockEmpty(toReplace)) {
            replaceBlock(world, pos->x, pos->y, user->currentBlock);
        }
    }

}
