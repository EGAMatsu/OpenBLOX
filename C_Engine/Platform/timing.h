double previousTime = 0;
float deltaTime;

double deltaTimeCalc() {
    double currentTime = (double)cpuGetTiming();
    double dt = ((currentTime-previousTime)/1000000.0000)/30;
    previousTime = currentTime;
    return dt;
}   