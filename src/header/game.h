#ifndef GAME_H
#define GAME_H
#include "menu.h"
#include "player.h"

typedef enum gameState
{
    PLAY,
    PAUSE,
    MENU,
    HELP
} State;

typedef struct frameInformation
{
    int currentFrame;
    int framesCounter;
    int framesSpeed;
    Rectangle frameRec;
} frameInformation;

// LIFECYCLE
void Init();
void Update();
void Draw();
void Destroy();

void InitGame();
void InitFrameData(Texture2D* sheet);
void controlAnimation(frameInformation* data, Texture2D* sheet);
void cropSpriteSheetOnDirection(Texture2D* sheet);
void updateGameState();

extern const char* GAME_TITLE;
extern int screenHeight;
extern int screenWidth;
extern Vector2 playerPosition;
extern State currentState;
extern frameInformation frameData;
extern moveDirection dir;
extern menuButtons STRUCT_MENU_BUTTONS;

extern Image playerImage;
extern Image playerSpriteSheet;
extern Texture2D Player;
extern Texture2D sheet;

#endif