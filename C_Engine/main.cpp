#include <stdio.h>

#include "./importantIncludes.h"
#include "./rbxl.h"

int main()
{
    // Enable printing debug info
    enableDebugConsole(1);
    systemStart();
    currentLanguageCode=0;

    // Print hello and platform
    char string[128];
    sprintf(string, "%s: %s\n%s: %s",
            strings_debug[STRING_CURRENT_LANGUAGE][currentLanguageCode], locale_names[currentLanguageCode],
            strings_debug[STRING_CURRENT_PLATFORM][currentLanguageCode], strings_platform[STRING_PLATFORM_DS______][currentLanguageCode]);
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