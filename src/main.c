#include "./header/game.h"

int main(void)
{
    Init();

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    
    Destroy();
    CloseWindow();

    return 0;
}
