/*
    OpenBLOX Math Helper
*/

#ifndef _MATHHELP
#define _MATHHELP

#include <cmath>

float lengthdir_x(float length, float dir) {
    return length * sin(-dir*0.0174533);
}

float lengthdir_y(float length, float dir) {
    return length * cos(-dir*0.0174533);
}

float lengthdir_z(float length, float dir) {
    return length * sin(-dir*0.0174533);
}

float clamp(float value, float min, float max) {
    if (value > max) {
        return max;
    } else if (value < min) {
        return min;
    } else {
        return value;
    }
}

#endif