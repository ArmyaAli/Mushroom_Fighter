#include "./header/game.h"

void Init()
{
    /* MUST BE CALLED BEFORE ANY LOADING OF TEXTURES */
    InitWindow(screenWidth, screenHeight, GAME_TITLE);
    InitMenu();
    InitGame();
    SetTargetFPS(60);
    InitFrameData(&sheet);
}

void Update()
{
    controlAnimation(&frameData, &sheet);
    cropSpriteSheetOnDirection(&sheet);
    updateGameState();
    updatePlayerPosition((Vector2){Player.width, Player.width});
}

void Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    switch (currentState)
    {
    case MENU:
        drawMenu();
        break;
    case HELP:
        DrawRectangleRec(STRUCT_MENU_BUTTONS.PLAY_BUTTON, GREEN);
        DrawText("You are in the HELP screen", 360, 370, 24, GRAY);
        break;
    case PLAY:
        DrawTextureRec(sheet, frameData.frameRec, (Vector2){playerPosition.x, playerPosition.y}, WHITE);
        DrawText("Welcome to Mushroom Fighter", 360, 370, 24, GRAY);
        break;
    case PAUSE:
        DrawText("You are in the Pause screen", 360, 370, 24, GRAY);
        break;
    }
    EndDrawing();
}

void Destroy()
{
    UnloadTexture(Player);
    UnloadTexture(sheet);
}
