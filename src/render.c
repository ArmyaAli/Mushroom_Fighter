#include "render.h"
#include <stdio.h>
#include "logger.h"
#include "enums.h"
#include "structs.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern int CURR_GAME_STATE;

// Game players
Player player_1;
Player player_2;

void draw_menu()
{
    const button_width = WINDOW_WIDTH / 2;

    char *buttons[5] = {"PLAY", "HELP", "CONTROLS", "CREDITS", "EXIT"};
    for (int i = 0; i < 5; ++i)
    {
        if (GuiButton((Rectangle){(button_width / 2), i * 50, button_width, 25}, buttons[i]))
        {
            CURR_GAME_STATE = 0;
            if (i == 0)
            {
                CURR_GAME_STATE = GAME;
                init_game();
            }
        }
    }
}

void init_game()
{
    LOG(INFO, "BEGIN init_game()");

    Vector2 p1_start = (Vector2) {16.0f, (float) WINDOW_HEIGHT - 64.0f };
    Vector2 p2_start = (Vector2) {WINDOW_WIDTH - 64.0f , (float) WINDOW_HEIGHT - 64.0f };

    player_1.pos = p1_start;
    player_1.vel = (Vector2){0.0f, 0.0f};
    player_1.acc = (Vector2){0.0f, 0.0f};
    player_1.size = (Vector2){32.0f, 32.0f};
    player_1.rotation = 1.0f;
    player_1.scale = 0.1f;
    player_1.color = WHITE;
    player_1.tex = LoadTexture("assets/players/without background/1.png");

    player_2.pos = p2_start;
    player_2.vel = (Vector2){0.0f, 0.0f};
    player_2.acc = (Vector2){0.0f, 0.0f};
    player_2.size = (Vector2){32.0f, 32.0f};
    player_2.rotation = 1.0f;
    player_2.scale = 0.1f;
    player_2.color = WHITE;
    player_2.tex = LoadTexture("assets/players/without background/2.png");

    LOG(INFO, "END init_game()");
}

void update_game()
{
    LOG(INFO, "BEGIN update_game()");

    if (player_1.pos.x <= WINDOW_WIDTH - 64.0f && IsKeyDown(KEY_D)) player_1.pos.x += 10;
    if (player_1.pos.x >= 16.0f && IsKeyDown(KEY_A)) player_1.pos.x -= 10;
    if (player_1.pos.y >= 16.0f && IsKeyDown(KEY_W)) player_1.pos.y -= 10;
    if (player_1.pos.y <= WINDOW_HEIGHT - 64.0f && IsKeyDown(KEY_S)) player_1.pos.y += 10;

    if (player_2.pos.x <= WINDOW_WIDTH - 64.0f && IsKeyDown(KEY_RIGHT)) player_2.pos.x += 10;
    if (player_2.pos.x >= 16.0f && IsKeyDown(KEY_LEFT)) player_2.pos.x -= 10;
    if (player_2.pos.y >= 16.0f && IsKeyDown(KEY_UP)) player_2.pos.y -= 10;
    if (player_2.pos.y <= WINDOW_HEIGHT - 64.0f && IsKeyDown(KEY_DOWN)) player_2.pos.y += 10;

    LOG(INFO, "END update_game()");
}

void draw_game()
{
    LOG(INFO, "BEGIN draw_game()");

    // LOG(INFO, "Drawing: Grid");
    // DrawRectangle(5, 100, WINDOW_WIDTH - 11, 200, RED);

    LOG(INFO, "Drawing: Player_1");
    DrawTextureEx(player_1.tex, player_1.pos, player_1.rotation, player_1.scale, player_1.color);

    LOG(INFO, "Drawing: Player_2");
    DrawTextureEx(player_2.tex, player_2.pos, player_2.rotation, player_2.scale, player_2.color);

    LOG(INFO, "END draw_game()");
}
