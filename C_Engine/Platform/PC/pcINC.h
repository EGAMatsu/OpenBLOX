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