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

touchPosition	thisXY;
touchPosition	lastXY = { 0,0,0,0 };
void processInput() {
    scanKeys();
    int held = keysHeld();
    look_horizontal_axis = 0;
    look_vertical_axis = 0;

	if (held & KEY_TOUCH)   {
        touchRead(&thisXY);

        s16 dx = thisXY.px - lastXY.px;
        s16 dy = thisXY.py - lastXY.py;

		if (dx<20 && dx>-20 && dy<20 && dy>-20) {
			if(dx>-3&&dx<3)
				dx=0;
			if(dy>-2&&dy<2) dy=0;
                look_horizontal_axis = dx;
                look_vertical_axis = dy;
			}

		lastXY = thisXY;
	}

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
    horizontal_axis = (button_left ? 1.0f : 0.0f) - (button_right ? 1.0f : 0.0f);
    fly_vertical_axis = (button_l ? 1.0f : 0.0f) - (button_r ? 1.0f : 0.0f);

    float yy_move = lengthdir_z(-vertical_axis, camera_rx);
    float yM_move = abs(1.0 - lengthdir_z(1, camera_rx));
    float xx_move = lengthdir_x(vertical_axis*yM_move, camera_ry) + lengthdir_x(horizontal_axis, camera_ry+90);
    float zz_move = lengthdir_y(vertical_axis*yM_move, camera_ry) + lengthdir_y(horizontal_axis, camera_ry+90);

    camera_x += (xx_move*64) * deltaTime;
    camera_y += (yy_move*64) * deltaTime;
    camera_z += (zz_move*64) * deltaTime;

    camera_ry += (look_horizontal_axis*15) * deltaTime;
    camera_rx -= (look_vertical_axis*15) * deltaTime;
    camera_rx = clamp(camera_rx, -90, 90);
}
