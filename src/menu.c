#include "./header/menu.h"

menuButtons STRUCT_MENU_BUTTONS;

void initMenu()
{
    STRUCT_MENU_BUTTONS.PLAY_BUTTON = (Rectangle){screenWidth / 2 - 100, screenHeight / 4 - 40, 200, 80};
    STRUCT_MENU_BUTTONS.HELP_BUTTON = (Rectangle){screenWidth / 2 - 100, screenHeight / 4 + 80, 200, 80};
    STRUCT_MENU_BUTTONS.EXIT_BUTTON = (Rectangle){screenWidth / 2 - 100, screenHeight / 4 + 200, 200, 80};
}

void drawMenu()
{
    // PLAY BUTTON
    DrawRectangle(screenWidth / 2 - 100, screenHeight / 4 - 40, 200, 80, GREEN);
    // HELP BUTTON
    DrawRectangle(screenWidth / 2 - 100, screenHeight / 4 + 80, 200, 80, BLUE);
    // EXIT BUTTON
    DrawRectangle(screenWidth / 2 - 100, screenHeight / 4 + 200, 200, 80, RED);
}