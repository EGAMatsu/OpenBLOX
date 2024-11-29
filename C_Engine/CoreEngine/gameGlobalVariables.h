/*
    OpenBLOX global variables
*/

unsigned char isGameRunning = 1;
unsigned char isDebgRunning = 0;

#define MINIGAME_MODE 0
#define PLAYSOLO_MODE 1
#define ONLINEPL_MODE 2
#define __STUDIO_MODE 3

unsigned char runtimeMode = 0

void gameRenderLoop();