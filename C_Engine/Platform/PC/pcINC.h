/*
    OpenBLOX PC Includes
*/

#ifndef NO_SDL
    #include <SDL/SDL.h>
#endif


#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <unistd.h>

#include "pc_function_debug.h"
#include "pc_function_opnGL.h"
#include "pc_function_time.h"

#define SENSITIVITY 0.2f

float maxPartDist = 256;

char filePathForProgram[1024];
const char* platformName = "Desktop";

void systemStart()  {
    printf("Starting Engine.\n");
    platSingleApp = 0;
    startEngine = 1;

    #ifndef WII_BUILD
        if (getcwd(filePathForProgram, sizeof(filePathForProgram)) != NULL) {
            printf("Current working directory: %s\n", filePathForProgram);
        } else {
            perror("getcwd() error");
        }
        printf("Done with init startup, resuming.\n");
    #else
        wiiInit();

        if (!fatInitDefault()) {
            printf("fatInitDefault failure: terminating\n");
            startEngine = 0;
        }
        sprintf(filePathForProgram, "sd:/");
    #endif
}

bool keyboard[2048] = { false };
unsigned char key_w = 0;
unsigned char key_s = 0;
unsigned char key_a = 0;
unsigned char key_d = 0;
unsigned char key_q = 0;
unsigned char key_e = 0;


void processInput() {
    #ifndef WII_BUILD
        const Uint8 *state = SDL_GetKeyState(NULL);
        
        for (int i = 0; i < 2048; ++i) {
            keyboard[i] = state[i] ? true : false;
        }

        key_w = keyboard[SDLK_w];
        key_s = keyboard[SDLK_s];
        key_a = keyboard[SDLK_a];
        key_d = keyboard[SDLK_d];
        key_q = keyboard[SDLK_q];
        key_e = keyboard[SDLK_e];
    #else
        WPAD_ScanPads();
        u32 pressed = WPAD_ButtonsDown(0);

        key_w = ( pressed & WPAD_BUTTON_UP );
        key_s = ( pressed & WPAD_BUTTON_DOWN );
        key_a = ( pressed & WPAD_BUTTON_LEFT );
        key_d = ( pressed & WPAD_BUTTON_RIGHT );
        key_q = ( pressed & WPAD_BUTTON_B );
        key_e = ( pressed & WPAD_BUTTON_A );
    #endif

    vertical_axis = (key_s ? 1.0f : 0.0f) - (key_w ? 1.0f : 0.0f);
    horizontal_axis = (key_a ? 1.0f : 0.0f) - (key_d ? 1.0f : 0.0f);
    fly_vertical_axis = (key_q ? 1.0f : 0.0f) - (key_e ? 1.0f : 0.0f);

    float yy_move = lengthdir_z(-vertical_axis, camera_rx);
    float yM_move = abs(1.0 - lengthdir_z(1, camera_rx));
    float xx_move = lengthdir_x(vertical_axis*yM_move, camera_ry) + lengthdir_x(horizontal_axis, camera_ry+90);
    float zz_move = lengthdir_y(vertical_axis*yM_move, camera_ry) + lengthdir_y(horizontal_axis, camera_ry+90);

    camera_x += (xx_move*64) * deltaTime;
    camera_y += ((yy_move+fly_vertical_axis)*64) * deltaTime;
    camera_z += (zz_move*64) * deltaTime;

    camera_ry += (float)mx * SENSITIVITY;
    camera_rx -= (float)my * SENSITIVITY;
    camera_rx = clamp(camera_rx, -90, 90);
}
