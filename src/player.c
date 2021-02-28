#include "./header/player.h"

static float playerVelocity = 2.0f;
Vector2 playerPosition      = {0.0f, 0.0f};

bool isPlayerMoving()
{
    return (IsKeyUp(KEY_D) && IsKeyUp(KEY_RIGHT)) && (IsKeyUp(KEY_A) && IsKeyUp(KEY_LEFT)) &&
           (IsKeyUp(KEY_W) && IsKeyUp(KEY_UP)) && (IsKeyUp(KEY_S) && IsKeyUp(KEY_DOWN));
}

void updatePlayerPosition(const Vector2 playerSize)
{
    if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && playerPosition.x < (float)(screenHeight - (playerSize.x + 8)))
    {
        dir = RIGHT;
        playerPosition.x += playerVelocity;
    }

    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && playerPosition.x > 0)
    {
        dir = LEFT;
        playerPosition.x -= playerVelocity;
    }

    if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && playerPosition.y > 0)
    {
        dir = UP;
        playerPosition.y -= playerVelocity;
    }

    if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && playerPosition.y < (float)(screenHeight - (playerSize.y + 8)))
    {
        dir = DOWN;
        playerPosition.y += playerVelocity;
    }
}
