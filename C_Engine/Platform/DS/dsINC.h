/*
    OpenBLOX DS Includes
*/

#include <nds.h>
#include <filesystem.h>
#include <fat.h>

#include "ds_function_debug.h"
#include "ds_function_opnGL.h"
#include "ds_function_time.h"

const char* platformName = "Nintendo DS(i)";

void fileStart();
void systemStart()  {
    cpuStartTiming(0);
    fileStart();
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