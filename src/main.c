#include "../raylib/include/raylib.h"
#include <stdio.h>

Vector2 playerPosition = {
    0.0f,
    0.0f};

const int screenHeight = 400;
const int screenWidth = 800;

void updatePlayerPosition();

int main(void)
{

    InitWindow(screenWidth, screenHeight, "Mushroom Fighter");

    // grab our sprite sheet
    Image playerImage = LoadImage("assets/playerhead.png");
    // crop area
    Rectangle first = {0, 0, 200, 4 * (128 / 4)};
    ImageCrop(&playerImage, first);
    Texture2D Player = LoadTextureFromImage(playerImage);
    printf("Height: %d Width: %d", Player.height, Player.width);
    SetTargetFPS(60);
    const Vector2 size = {Player.width, Player.width};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        updatePlayerPosition(size);
        ClearBackground(RAYWHITE);
        DrawTexture(Player, playerPosition.x, playerPosition.y, WHITE);
        DrawText("this IS a texture!", 360, 370, 10, GRAY);

        EndDrawing();
    }

    UnloadTexture(Player);

    CloseWindow();

    return 0;
}

void updatePlayerPosition(const Vector2 playerSize)
{
    const float vel = 6.0f;

    if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && playerPosition.x < (float)(screenWidth - playerSize.x))
    {
        playerPosition.x += vel;
        printf("xPos: %f, yPos: %f\n", playerPosition.x, playerPosition.y);
    }

    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && playerPosition.x > 0)
        playerPosition.x -= vel;
    if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && playerPosition.y > 0)
        playerPosition.y -= vel;
    if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && playerPosition.y < (float)(screenHeight - (playerSize.y + 10)))
        playerPosition.y += vel;
}