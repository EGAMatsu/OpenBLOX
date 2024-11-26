/*
    OpenBLOX DS Functions for Debugging
*/

void enableDebugConsole(unsigned char enable) {
    if (enable) { 
        consoleDemoInit();
    }
    isDebgRunning = enable;
}

void print_message(const char * text) {
    if (isDebgRunning) {
        printf(text);
    }
}