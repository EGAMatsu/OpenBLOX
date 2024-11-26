/*
    OpenBLOX PC Functions for Debugging
*/

void enableDebugConsole(unsigned char enable) {
    isDebgRunning = enable;
}

void print_message(const char * text) {
    if (isDebgRunning) {
        printf(text);
    }
}