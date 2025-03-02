#include <stdio.h>

#include "./importantIncludes.h"
Node *dataModel, *characterModel;

int main(int argc, char *argv[])
{
    // Enable printing debug info
    enableDebugConsole(1);
    systemStart();

    if (startEngine) {
        print_message("Start engine done, now loading data.\n");
        currentLanguageCode=0;

        // Print hello and platform
        print_message("%s: %s\n%s: %s\n",
                strings_debug[STRING_CURRENT_LANGUAGE][currentLanguageCode], locale_names[currentLanguageCode],
                strings_debug[STRING_CURRENT_PLATFORM][currentLanguageCode], strings_platform[platformNameLoc][currentLanguageCode]);
        
        print_message("Start to load.\n");

        if ( 1/*platSingleApp*/) {
            print_message("Loading...\n");
            loadFiles(&dataModel, &characterModel);
            print_message("Done.\n");
        }

        initOpenGL();
        perspectiveModeGL();

        while(isGameRunning) {
            processInput();
            gameRenderLoop();

            deltaTime = deltaTimeCalc();
        }

        return 0;
    } else {
        print_message("ERROR, ENGINE KILLED.\n\nIf you need help, look at:\n\nhttps://github.com/EGAMatsu/OpenBLOX/blob/main/README.md\n\nfor help, else join the discord:\nWf2bbU5z5J");
        while(1) {
            // Do nothing.
        }
    }
}

float test = 0;
void gameRenderLoop() {
    setupLighting();
    start3DFrame();
        test += 45*deltaTime;
        /*scale_rotate_translate(1,1,1, -90,180,0, 0,0,0);
        scale_rotate_translate(1,1,1, 0,0,0, debug_camera_x,debug_camera_y,debug_camera_z);*/
        scale_rotate_translate(1,1,1, 0, test, 0, 0,0,0);
        scale_rotate_translate(1,1,1, 0, 0, 0, 0,-16,0);
        renderWorld(dataModel);
    endFrame();
}
