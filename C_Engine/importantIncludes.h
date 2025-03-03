#ifndef _IMPORTANT_INCLUDES
#define _IMPORTANT_INCLUDES

// Engine core that should be defined before the core platform includes
#include "CoreEngine/gameGlobalVariables.h"
#include "CoreEngine/timing.h"
#include "ThirdParty/xml/include/xml.h"

// Physics
#include "ThirdParty/TinyPhysicsEngine/tinyphysicsengine.h"
TPE_World world;    // The physical world.

float distanceBetweenPoints(float x1, float y1, float z1, float x2, float y2, float z2);
float averageSize(float x, float y, float z);
void print_message(const char * text, ...);
unsigned char startEngine   = 0;
unsigned char platSingleApp = 0;

float camera_x = 0;
float camera_y = -16;
float camera_z = 0;

float vertical_axis = 0.0;
float horizontal_axis = 0.0;
float look_vertical_axis = 0.0;
float look_horizontal_axis = 0.0;
float fly_vertical_axis = 0.0;

unsigned char jump = 0;
unsigned char backpackItem = 0;

#ifdef NDS_BUILD
    #define platformNameLoc STRING_PLATFORM_DS______
    #include "Platform/DS/dsINC.h"
#else
    #define platformNameLoc STRING_PLATFORM_PC______
    #include "Platform/PC/pcINC.h"
#endif

// Post platform includes
#include "CoreEngine/color.h"
#include "CoreEngine/GL/gameGL_globals.h"

// Level/Model stuff
#include "CoreEngine/Node/nodes.h"
#include "./rbxl.h"

#ifdef NDS_BUILD
    #include "Platform/DS/ds_function_loading.h"
#else
    #include "Platform/PC/pc_function_loading.h"
#endif

#endif
