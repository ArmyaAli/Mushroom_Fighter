#include "raylib.h"
#include "logger.h"
#include "render.h"
#include "constants.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

extern int CURR_GAME_STATE;

// Entry point 
int main()
{
    // SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mushroom Fighter");

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        resolveGameState();

        EndDrawing();
    }

    CloseWindow(); 

    return 0;
}

resolveGameState() {
    switch(CURR_GAME_STATE) {
        case MENU:
            draw_menu(); break;
        case GAME:
            draw_game(); 
            update_game();
            break;
        case GAME_PAUSED:
            break;
    }
}