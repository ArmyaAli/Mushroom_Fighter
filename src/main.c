#include "raylib.h"
#include "constants.h"
#include "logger.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400


int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mushroom Fighter");

    SetTargetFPS(60);               

    LOG(DEBUG, "Hello my name is Ali");
    while (!WindowShouldClose())    
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
