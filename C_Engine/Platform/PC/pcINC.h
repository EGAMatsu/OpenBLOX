/*
    OpenBLOX PC Includes
*/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <unistd.h>

#include "pc_function_debug.h"
#include "pc_function_opnGL.h"
#include "pc_function_time.h"

char filePathForProgram[1024];
const char* platformName = "Desktop";

void systemStart()  {
    printf("Starting Engine.\n");
    platSingleApp = 0;
    startEngine = 1;

    if (getcwd(filePathForProgram, sizeof(filePathForProgram)) != NULL) {
        printf("Current working directory: %s\n", filePathForProgram);
    } else {
        perror("getcwd() error");
    }
    printf("Done with init startup, resuming.\n");
}

bool keyboard[2048] = { false };

void processInput() {
    const Uint8 *state = SDL_GetKeyState(NULL);
    
    for (int i = 0; i < 2048; ++i) {
        keyboard[i] = state[i] ? true : false;
    }

    vertical_axis = (keyboard[SDLK_s] ? 1.0f : 0.0f) - (keyboard[SDLK_w] ? 1.0f : 0.0f);
    horizontal_axis = (keyboard[SDLK_d] ? 1.0f : 0.0f) - (keyboard[SDLK_a] ? 1.0f : 0.0f);
    fly_vertical_axis = (keyboard[SDLK_q] ? 1.0f : 0.0f) - (keyboard[SDLK_e] ? 1.0f : 0.0f);

    debug_camera_x += (horizontal_axis*64) * deltaTime;
    debug_camera_y += (fly_vertical_axis*64) * deltaTime;
    debug_camera_z += (vertical_axis*64) * deltaTime;
}
