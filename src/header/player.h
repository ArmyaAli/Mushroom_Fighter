#include "../../raylib/include/raylib.h"
#ifndef PLAYER_H
#define PLAYER_H

typedef enum moveDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} moveDirection;

void InitMenu();
void updatePlayerPosition();
bool isPlayerMoving();

extern moveDirection dir;
extern Vector2 playerPosition;

extern int screenHeight;
extern int screenWidth;

#endif