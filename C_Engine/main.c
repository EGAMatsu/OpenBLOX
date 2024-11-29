#include "Platform/gameGlobalVariables.h"

#include <stdio.h>
#include "CoreEngine/color.h"
#include "ThirdParty/TinyPhysicsEngine/tinyphysicsengine.h"

#ifdef NDS_BUILD
    #include "Platform/DS/dsINC.h"
#elif   PC_BUILD
    #include "Platform/PC/pcINC.h"
#endif

#include "Platform/gameGL_globals.h"
#include "Platform/timing.h"

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
    render_cube_transform(0, 0, 2, 0, test, 0, 1, 1, 1);
    endFrame();
}