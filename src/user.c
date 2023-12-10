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
