/*
    OpenBLOX PC Functions for Debugging
*/

#include <stdarg.h>

void enableDebugConsole(unsigned char enable) {
    if (enable) { 
        consoleDemoInit();
    }
    isDebgRunning = enable;
}

void vprint_message(const char * text, va_list args)
{
    if (isDebgRunning)
    {
        vprintf(text, args);
    }
}

void print_message(const char * text, ...) {
    va_list args;

    va_start(args, text);

    vprint_message(text, args);

    va_end(args);
}
