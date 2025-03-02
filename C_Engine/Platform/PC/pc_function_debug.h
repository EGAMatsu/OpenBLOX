/*
    OpenBLOX PC Functions for Debugging
*/

void enableDebugConsole(unsigned char enable) {
    isDebgRunning = enable;
}

void vprint_message(const char * text, va_list args)
{
    if (isDebgRunning)
    {
        printf(text, args);
    }
}

#define print_message printf