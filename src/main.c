#include "../raylib/include/raylib.h"
#include <stdio.h>

#define MAX_FRAME_SPEED 15
#define MIN_FRAME_SPEED 1

typedef enum moveDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} moveDirection;

typedef struct frameInformation
{
    int currentFrame;
    int framesCounter;
    int framesSpeed;
    Rectangle frameRec;
} frameInformation;

Vector2 playerPosition =
{
    0.0f,
    0.0f
};

const int screenHeight = 400;
const int screenWidth = 800;

moveDirection dir;

void updatePlayerPosition();
bool isPlayerMoving();
void controlAnimation(frameInformation *data, Texture2D *sheet);
void cropSpriteSheetOnDirection(frameInformation *data, Texture2D *sheet);

int main(void)
{
    /* MUST BE CALLED BEFORE ANY LOADING OF TEXTURES */
    InitWindow(screenWidth, screenHeight, "Mushroom Fighter");

    Image playerImage = LoadImage("assets/playerhead.png");
    Image playerSpriteSheet = LoadImage("assets/player.png");

    Texture2D Player = LoadTextureFromImage(playerImage);
    Texture2D sheet = LoadTextureFromImage(playerSpriteSheet);

    SetTargetFPS(60);

    frameInformation frameData = 
    {
        0,
        0, 
        4, 
        {0.0f, 0.0f, (float)sheet.width / 4, (float)sheet.height / 4}
    };

    while (!WindowShouldClose())
    {
        controlAnimation(&frameData, &sheet);
        cropSpriteSheetOnDirection(&frameData, &sheet);

        BeginDrawing();

        updatePlayerPosition((Vector2){Player.width, Player.width});
        ClearBackground(RAYWHITE);
        DrawTextureRec(sheet, frameData.frameRec, (Vector2){playerPosition.x, playerPosition.y}, WHITE);
        DrawText("Welcome to Mushroom Fighter", 360, 370, 24, GRAY);
        
        EndDrawing();
    }

    UnloadTexture(Player);
    UnloadTexture(sheet);

    CloseWindow();

    return 0;
}

void cropSpriteSheetOnDirection(frameInformation *data, Texture2D *sheet)
{
    switch (dir)
    {
    case LEFT:
        data->frameRec.y = 1 * (float)(sheet->width / 4);
        break;
    case RIGHT:
        data->frameRec.y = 2 * (float)(sheet->width / 4);
        break;
    case UP:
        data->frameRec.y = 3 * (float)(sheet->width / 4);
        break;
    case DOWN:
        data->frameRec.y = 0 * (float)(sheet->width / 4);
        break;
    }
}

void controlAnimation(frameInformation *data, Texture2D *sheet)
{
    data->framesCounter++;

    if (data->framesCounter >= (60 / data->framesSpeed) && !isPlayerMoving())
    {
        printf("moving");
        data->framesCounter = 0;
        data->currentFrame++;

        if (data->currentFrame > 3)
            data->currentFrame = 0;
        data->frameRec.x = (float)data->currentFrame * (float)sheet->width / 4;
    }
}

bool isPlayerMoving()
{
    return (IsKeyUp(KEY_D) && IsKeyUp(KEY_RIGHT)) &&
           (IsKeyUp(KEY_A) && IsKeyUp(KEY_LEFT)) &&
           (IsKeyUp(KEY_W) && IsKeyUp(KEY_UP)) &&
           (IsKeyUp(KEY_S) && IsKeyUp(KEY_DOWN));
}

void updatePlayerPosition(const Vector2 playerSize)
{
    const float vel = 2.0f;

    if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && playerPosition.x < (float)(screenWidth - (playerSize.x + 8)))
    {
        dir = RIGHT;
        playerPosition.x += vel;
    }

    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && playerPosition.x > 0)
    {
        dir = LEFT;
        playerPosition.x -= vel;
    }

    if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && playerPosition.y > 0)
    {
        dir = UP;
        playerPosition.y -= vel;
    }

    if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && playerPosition.y < (float)(screenHeight - (playerSize.y + 8)))
    {
        dir = DOWN;
        playerPosition.y += vel;
    }
}