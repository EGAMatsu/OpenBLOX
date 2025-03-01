#include <stdio.h>

#include "./importantIncludes.h"
Node *dataModel, *characterModel;

int main()
{
    // Enable printing debug info
    enableDebugConsole(1);
    systemStart();

    if (startEngine) {
        currentLanguageCode=0;

        // Print hello and platform
        print_message("%s: %s\n%s: %s",
                strings_debug[STRING_CURRENT_LANGUAGE][currentLanguageCode], locale_names[currentLanguageCode],
                strings_debug[STRING_CURRENT_PLATFORM][currentLanguageCode], strings_platform[STRING_PLATFORM_DS______][currentLanguageCode]);
        
        if (platSingleApp) {
            print_message("Loading...");
            loadFiles(&dataModel, &characterModel);
            print_message("Done.");
        }

        initOpenGL();
        perspectiveModeGL();

        while(isGameRunning) {
            gameRenderLoop();

            deltaTime = deltaTimeCalc();
        }

        return 0;
    } else {
        print_message("If you need help, look at:\n\nhttps://github.com/EGAMatsu/OpenBLOX/blob/main/README.md\n\nfor help, else join the discord:\nWf2bbU5z5J");
        while(1) {
            // Do nothing.
        }
    }
}

float test = 0;
void gameRenderLoop() {
    start3DFrame();
    test += 90*deltaTime;
        /*render_cube_transform(0, 0, 2, 0, test, 0, 1, 1, 1, 1);
        render_cube_transform(3, 1, 4, 0, test, 0, 1, 1, 1, 26);
        render_cube_transform(-3, 1, 4, 0, test, 0, 1, 1, 1, 137);*/
        renderWorld(dataModel);
    endFrame();
}
