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

const int screenHeight = 400;
const int screenWidth = 800;
moveDirection dir;
Vector2 playerPosition = {
    0.0f,
    0.0f};

void updatePlayerPosition();

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Mushroom Fighter");

    // grab our sprite sheet
    Image playerImage = LoadImage("assets/playerhead.png");
    Image playerSpriteSheet = LoadImage("assets/player.png");

    Texture2D Player = LoadTextureFromImage(playerImage);
    Texture2D sheet = LoadTextureFromImage(playerSpriteSheet);

    printf("Height: %d Width: %d", Player.height, Player.width);
    SetTargetFPS(30);
    int i = 0;
    int currentFrame = 0;

    int framesCounter = 0;
    int framesSpeed = 6; // Number of spritesheet frames shown by second
    Rectangle frameRec = {0.0f, 0.0f, (float)sheet.width / 4, (float)sheet.height / 4};

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        framesCounter++;
        bool notMoving = (IsKeyUp(KEY_D) && IsKeyUp(KEY_RIGHT)) &&
                         (IsKeyUp(KEY_A) && IsKeyUp(KEY_LEFT)) &&
                         (IsKeyUp(KEY_W) && IsKeyUp(KEY_UP)) &&
                         (IsKeyUp(KEY_S) && IsKeyUp(KEY_DOWN));
        printf("moving: %d\n", notMoving);
        if (framesCounter >= (60 / framesSpeed) && !notMoving)
        {
            printf("moving");
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3)
                currentFrame = 0;
            frameRec.x = (float)currentFrame * (float)sheet.width / 4;
        }

        if (dir == LEFT)
        {
            frameRec.y = 1 * (float)(sheet.width / 4);
        }

        if (dir == RIGHT)
        {
            frameRec.y = 2 * (float)(sheet.width / 4);
        }

        if (dir == UP)
        {
            frameRec.y = 3 * (float)(sheet.width / 4);
        }

        if (dir == DOWN)
        {
            frameRec.y = 0 * (float)(sheet.width / 4);
        }

        BeginDrawing();
        printf("%d\n", dir);
        updatePlayerPosition((Vector2){Player.width, Player.width});
        ClearBackground(RAYWHITE);
        //DrawTexture(Player, playerPosition.x, playerPosition.y, WHITE);
        // number of sprites to show

        DrawTextureRec(sheet, frameRec, (Vector2){playerPosition.x, playerPosition.y}, WHITE);
        i++;
        if (i > 3)
            i = 0;
        DrawText("this IS a texture!", 360, 370, 10, GRAY);
        EndDrawing();
    }

    UnloadTexture(Player);
    UnloadTexture(sheet);

    CloseWindow();

    return 0;
}

void updatePlayerPosition(const Vector2 playerSize)
{
    const float vel = 6.0f;

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