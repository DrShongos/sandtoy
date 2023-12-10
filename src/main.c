#include <stdio.h>
#include <raylib.h>
#include "world.h"
#include "user.h"

#define WIDTH 800
#define HEIGHT 800

#define TICKRATE 3

int main()
{
    InitWindow(WIDTH, HEIGHT, "Sandtoy");

    SetTargetFPS(60);

    World_t world = createWorld(100, 100);
    *getBlockAt(&world, 0, 0) = BLOCK_SAND;
    *getBlockAt(&world, 20, 8) = BLOCK_SAND;
    *getBlockAt(&world, 20, 7) = BLOCK_SAND;
    *getBlockAt(&world, 20, 6) = BLOCK_SAND;
    *getBlockAt(&world, 20, 5) = BLOCK_SAND;
    *getBlockAt(&world, 20, 4) = BLOCK_SAND;
    *getBlockAt(&world, 20, 3) = BLOCK_SAND;
    *getBlockAt(&world, 20, 2) = BLOCK_SAND;
    *getBlockAt(&world, 0, 7) = BLOCK_SAND;
    *getBlockAt(&world, 0, 6) = BLOCK_SAND;
    *getBlockAt(&world, 0, 5) = BLOCK_SAND;

    int ticks = 0;

    while(!WindowShouldClose()) {
        if (ticks % TICKRATE == 0) {
            updateWorld(&world);
            ticks = 0;
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            WorldPosition_t pos = getClickWorldPosition();            
            replaceBlock(&world, pos.x, pos.y, BLOCK_SAND);
        }

        BeginDrawing();

        ClearBackground(BLACK); 

        for (int y = 0; y < world.height; y++) {
            for (int x = 0; x < world.width; x++) {
                drawBlockAt(&world, x, y);
            }
        } 

        EndDrawing();
        ticks++;
    }

    deleteWorld(&world);

    CloseWindow();
    return 0;
}
