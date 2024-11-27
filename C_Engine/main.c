#include "Platform/gameGlobalVariables.h"

#include <stdio.h>
#ifdef NDS_BUILD
    #include "Platform/DS/dsINC.h"
#elif   PC_BUILD
    #include "Platform/PC/pcINC.h"
#endif

#include "Platform/gameGL_globals.h"

int main()
{
    // Enable printing debug info
    enableDebugConsole(1);

    // Print hello and platform
    char* string = malloc(128*sizeof(char));
    sprintf(string, "OpenBLOX says Hi.\nCurrent Platform: %s", platformName);
    print_message(string);

    initOpenGL();
    perspectiveModeGL();

    while(isGameRunning) {
        // Do NOTHING.
        start3DFrame();
        render_cube_transform(0, 0, 2);
        endFrame();
    }

    return 0;
}