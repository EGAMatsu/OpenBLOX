/*
    OpenBLOX DS Time
*/

#include <time.h>

clock_t get_clock_time() {
    return clock();
}

double deltaTimeCalc() {
    static double previousTime = 0.0;

    struct timespec currentTimeSpec;
    clock_gettime(CLOCK_REALTIME, &currentTimeSpec);
    double currentTime = currentTimeSpec.tv_sec + currentTimeSpec.tv_nsec / 1e9;

    double dt = (currentTime - previousTime) / 30.0;
    previousTime = currentTime;
    return dt;
}
