#include "./header/game.h"

const char* GAME_TITLE = "Mushroom Fighter";
int screenWidth        = 800;
int screenHeight       = 400;

frameInformation frameData;
Image playerImage;
Image playerSpriteSheet;
Texture2D Player;
Texture2D sheet;
State currentState;

void InitGame()
{
    currentState      = MENU;
    playerImage       = LoadImage("assets/playerhead.png");
    playerSpriteSheet = LoadImage("assets/player.png");
    Player            = LoadTextureFromImage(playerImage);
    sheet             = LoadTextureFromImage(playerSpriteSheet);
}

void InitFrameData(Texture2D* sheet)
{
    frameData.currentFrame  = 0;
    frameData.framesCounter = 0;
    frameData.framesSpeed   = 4;
    frameData.frameRec      = (Rectangle){0, 0, (float)sheet->width / 4, (float)sheet->height / 4};
}

void controlAnimation(frameInformation* data, Texture2D* sheet)
{
    data->framesCounter++;

    if (data->framesCounter >= (60 / data->framesSpeed) && !isPlayerMoving())
    {
        data->framesCounter = 0;
        data->currentFrame++;

        if (data->currentFrame > 4)
            data->currentFrame = 0;
        data->frameRec.x = (float)data->currentFrame * (float)sheet->width / 4;
    }
}

void cropSpriteSheetOnDirection(Texture2D* sheet)
{
    switch (dir)
    {
    case LEFT:
        frameData.frameRec.y = 1 * (float)(sheet->width / 4);
        break;
    case RIGHT:
        frameData.frameRec.y = 2 * (float)(sheet->width / 4);
        break;
    case UP:
        frameData.frameRec.y = 3 * (float)(sheet->width / 4);
        break;
    case DOWN:
        frameData.frameRec.y = 0 * (float)(sheet->width / 4);
        break;
    }
}

void updateGameState()
{
    Vector2 mousePos = GetMousePosition();
    // printf("%d %d \n", dir, currentSTATE);
    switch (currentState)
    {
    case MENU:
        if (CheckCollisionPointRec(mousePos, STRUCT_MENU_BUTTONS.PLAY_BUTTON))
        {
            if (IsMouseButtonPressed(0))
                currentState = PLAY;
        }
        else if (CheckCollisionPointRec(mousePos, STRUCT_MENU_BUTTONS.HELP_BUTTON))
        {
            if (IsMouseButtonPressed(0))
                currentState = HELP;
        }
        else if (CheckCollisionPointRec(mousePos, STRUCT_MENU_BUTTONS.EXIT_BUTTON))
        {
            if (IsMouseButtonPressed(0))
                CloseWindow();
        }
        break;
    case PLAY:
        if (IsKeyPressed(KEY_P))
        {
            currentState = PAUSE;
        }
        break;
    case PAUSE:
        if (IsKeyPressed(KEY_P))
        {
            currentState = PLAY;
        }
        break;
    case HELP:
        // if (IsKeyPressed(KEY_ESCAPE))
        // {
        //     currentState = MENU;
        // }
        break;
    }
}
