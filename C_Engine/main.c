#include <stdio.h>

#include "CoreEngine/gameGlobalVariables.h"
#include "CoreEngine/color.h"
#include "CoreEngine/timing.h"

#include "ThirdParty/TinyPhysicsEngine/tinyphysicsengine.h"

#ifdef NDS_BUILD
    #include "Platform/DS/dsINC.h"
#elif   PC_BUILD
    #include "Platform/PC/pcINC.h"
#endif

#include "CoreEngine/GL/gameGL_globals.h"


int main()
{
    // Enable printing debug info
    enableDebugConsole(1);
    systemStart();

    // Print hello and platform
    char* string = malloc(128*sizeof(char));
    sprintf(string, "OpenBLOX says Hi.\nCurrent Platform: %s", platformName);
    print_message(string);

    initOpenGL();
    perspectiveModeGL();

    while(isGameRunning) {
        gameRenderLoop();

        deltaTime = deltaTimeCalc();
        sprintf(string, "DeltaTime: %f\n", deltaTime);
        //print_message(string);
    }

    return 0;
}

float test = 0;
void gameRenderLoop() {
    start3DFrame();
    test += 90*deltaTime;
    render_cube_transform(0, 0, 2, 0, test, 0, 1, 1, 1, 1);
    render_cube_transform(3, 1, 4, 0, test, 0, 1, 1, 1, 26);
    render_cube_transform(-3, 1, 4, 0, test, 0, 1, 1, 1, 137);
    endFrame();
}