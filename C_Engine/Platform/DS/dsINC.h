/*
    OpenBLOX DS Includes
*/

#include <nds.h>
#include <filesystem.h>
#include <fat.h>

#include "ds_function_debug.h"
#include "ds_function_opnGL.h"
#include "ds_function_time.h"

float maxPartDist = 128;

const char* platformName = "Nintendo DS(i)";

void fileStart();
void systemStart()  {
    cpuStartTiming(0);
    fileStart();
    platSingleApp = 1;
}

void fileStart() {
    /* Start up fs */
	if (fatInitDefault()) {
        print_message("fatInit success!\n");
        startEngine = 1;
	} else {
		print_message("fatInit failure\nEnsure you're emulator or cart\nproperly supports libfat;\nelse do the correct DLDI patches\n\n");
        startEngine = 0;
	}
}


void processInput() {
    scanKeys();
    int held = keysHeld();

    int button_up = (held & KEY_UP);
    int button_down = (held & KEY_DOWN);
    int button_left = (held & KEY_LEFT);
    int button_right = (held & KEY_RIGHT);

    int button_a = (held & KEY_A);
    int button_b = (held & KEY_B);
    int button_x = (held & KEY_X);
    int button_y = (held & KEY_Y);

    int button_l = (held & KEY_L);
    int button_r = (held & KEY_R);

    vertical_axis = (button_down ? 1.0f : 0.0f) - (button_up ? 1.0f : 0.0f);
    horizontal_axis = (button_right ? 1.0f : 0.0f) - (button_left ? 1.0f : 0.0f);
    fly_vertical_axis = (button_l ? 1.0f : 0.0f) - (button_r ? 1.0f : 0.0f);

    camera_x += (horizontal_axis*64) * deltaTime;
    camera_y += (fly_vertical_axis*64) * deltaTime;
    camera_z += (vertical_axis*64) * deltaTime;
}
