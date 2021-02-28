#ifndef MENU_H
#define MENU_H
#include "../../raylib/include/raylib.h"

typedef struct MENU_BUTTON
{
    Rectangle PLAY_BUTTON;
    Rectangle HELP_BUTTON;
    Rectangle EXIT_BUTTON;
} menuButtons;

void drawMenu();

extern int screenHeight, screenWidth;
extern menuButtons STRUCT_MENU_BUTTONS;

#endif