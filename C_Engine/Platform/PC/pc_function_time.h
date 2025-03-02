/*
    OpenBLOX DS Time
*/

#include <time.h>

clock_t get_clock_time() {
    return clock();
}

double deltaTimeCalc() {
    double currentTime = get_clock_time();
    double dt = ((currentTime - previousTime)/CLOCKS_PER_SEC)*0.5; // 30 FPS
    previousTime = currentTime;
    return dt;
}
