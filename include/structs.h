#include "raylib.h"

typedef struct _Player
{
    Vector2 pos;
    Vector2 vel;
    Vector2 acc;
    Vector2 size;
    float rotation;
    float scale;
    Color color;
    Texture2D tex;
} Player;

typedef struct _Grid
{
    Vector2 dim;
    int lr_gutter;
    int** grid;
    Color color;
} Grid;