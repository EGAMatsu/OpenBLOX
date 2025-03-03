/*

    OpenBLOX Revolution Functions (Important)

*/

#include <gccore.h>
#include <fat.h>
#include <wiiuse/wpad.h>


static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

void wiiInit() {
	VIDEO_Init();
	rmode = VIDEO_GetPreferredMode(NULL);
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(false);
	VIDEO_Flush();
	VIDEO_WaitVSync();
}