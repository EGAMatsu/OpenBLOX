#include <math.h>

double lengthdir_x(double length, double direction) {
return length * cos(direction * M_PI / 180);
}

double lengthdir_y(double length, double direction) {
return length * sin(direction * M_PI / 180);
}

float lerpAngle(float startAngle, float endAngle, float t)
{
    float delta = fmod((endAngle - startAngle + 180), 360) - 180;
    return startAngle + delta * t;
}

float rad2deg(float radians) {
	return radians * (180/M_PI);
}

float normalizeAngle(float angle) {
  while (angle < 0) {
    angle += 360;
  }
  while (angle >= 360) {
    angle -= 360;
  }
  return angle;
}


float clamp(float value, float min, float max) {
  return std::max(min, std::min(value, max));
}