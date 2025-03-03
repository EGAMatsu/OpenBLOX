/*

    OpenBLOX Revolution Functions (Important)

*/

#include <gccore.h>
#include <fat.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;
void wiiInit() {
    // Initialise the video system
	VIDEO_Init();

	// Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	rmode = VIDEO_GetPreferredMode(NULL);

	VIDEO_Configure(rmode);

	VIDEO_WaitVSync();
}