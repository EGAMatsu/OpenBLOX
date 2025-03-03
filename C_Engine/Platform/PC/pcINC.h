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
    #endif

    vertical_axis = (key_s ? 1.0f : 0.0f) - (key_w ? 1.0f : 0.0f);
    horizontal_axis = (key_d ? 1.0f : 0.0f) - (key_a ? 1.0f : 0.0f);
    fly_vertical_axis = (key_q ? 1.0f : 0.0f) - (key_e ? 1.0f : 0.0f);

    camera_x += (horizontal_axis*64) * deltaTime;
    camera_y += (fly_vertical_axis*64) * deltaTime;
    camera_z += (vertical_axis*64) * deltaTime;
}
