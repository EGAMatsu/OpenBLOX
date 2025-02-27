#ifndef _IMPORTANT_INCLUDES
#define _IMPORTANT_INCLUDES

// Engine core that should be defined before the core platform includes
#include "CoreEngine/gameGlobalVariables.h"
#include "CoreEngine/color.h"
#include "CoreEngine/timing.h"

// Third party pre-platform includes
#include "ThirdParty/TinyPhysicsEngine/tinyphysicsengine.h"

#ifdef NDS_BUILD
    #include "Platform/DS/dsINC.h"
#elif   PC_BUILD
    #include "Platform/PC/pcINC.h"
#endif

// Post platform includes
#include "CoreEngine/GL/gameGL_globals.h"
#include "CoreEngine/Node/nodes.h"
#include "ThirdParty/xml/include/xml.h"


#endif