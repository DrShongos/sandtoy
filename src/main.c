#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include "block.h"
#include "world.h"
#include "user.h"

#define WIDTH 800
#define HEIGHT 800

#define TICKRATE 2

int main()
{
    InitWindow(WIDTH, HEIGHT, "Sandtoy");

    SetTargetFPS(60);

    World_t world = createWorld(100, 100);

    User_t user;
    user.currentBlock = sandBlock();
    user.placementRadius = 1;

    int ticks = 0;

    srand(time(NULL));

    while(!WindowShouldClose()) {
        if (ticks % TICKRATE == 0) {
            updateWorld(&world);
            ticks = 0;
        }

        handleInput(&user, &world);

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
