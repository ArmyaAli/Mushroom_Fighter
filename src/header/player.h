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

moveDirection dir;

extern int screenHeight;
extern int screenWidth;

#endif