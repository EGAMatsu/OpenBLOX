/*
    OpenBLOX DS Includes
*/

#include <nds.h>
#include "ds_function_debug.h"
#include "ds_function_opnGL.h"
#include "ds_function_time.h"

const char* platformName = "Nintendo DS(i)";

void systemStart()  {
    cpuStartTiming(0);
}