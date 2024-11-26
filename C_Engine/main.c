#include "Platform/gameGlobalVariables.h"

#include <stdio.h>
#ifdef NDS_BUILD
    #include "Platform/DS/dsINC.h"
#elif   PC_BUILD
    #include "Platform/PC/pcINC.h"
#endif

int main()
{
    // Enable printing debug info
    enableDebugConsole(1);

    // Print hello and platform
    char* string = malloc(128*sizeof(char));
    sprintf(string, "OpenBLOX says Hi.\nCurrent Platform: %s", platformName);
    print_message(string);

    while(isGameRunning) {
        // Do NOTHING.
    }

    return 0;
}