#include "animation.h"
#include "raylib.h"
#include "enums.h"
#include "logger.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern int CURR_GAME_STATE;

void shroom_walk(Player* p)
{
    if (p->pos.x <= WINDOW_WIDTH - 64.0f && IsKeyDown(KEY_D)) p->pos.x += 10;
    if (p->pos.x >= 16.0f && IsKeyDown(KEY_A)) p->pos.x -= 10;
    if (p->pos.y >= 16.0f && IsKeyDown(KEY_W)) p->pos.y -= 10;
    if (p->pos.y <= WINDOW_HEIGHT - 64.0f && IsKeyDown(KEY_S)) p->pos.y += 10;    
}