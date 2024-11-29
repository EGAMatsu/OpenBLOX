/*
    OpenBLOX DS Time
*/

#include <time.h>
#include <sys/times.h>

clock_t get_clock_time() {
    struct tms tim_s;
    clock_t res;

    if ((res = (clock_t) times (&tim_s)) != (clock_t) -1)
        res = (clock_t) (tim_s.tms_utime + tim_s.tms_stime +
            tim_s.tms_cutime + tim_s.tms_cstime);

    return res;
}

double deltaTimeCalc() {
    double currentTime = (double)cpuGetTiming();
    double dt = ((currentTime-previousTime)/1000000.0000)/30;
    previousTime = currentTime;
    return dt;
}   