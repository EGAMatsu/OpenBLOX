#include "classes.h"

const float GRAVITY = 9.8f;  // acceleration due to gravity
const float TIME_STEP = 0.01f;  // time step for simulation

void Part::update(float time) {
  if (isAnchored) {
    // Anchored parts don't move
    return;
  }

  // Apply gravity
  if (!isAnchored) {
    //TODO: Implement physics API
  }

  // Check for collisions with other parts
  if (canCollide) {
    // TODO: implement collision detection and resolution here
  }

  // Update position and velocity based on forces
  pos_x += velocity_x * time;
  pos_y += velocity_y * time;
  pos_z += velocity_z * time;
  velocity_x += forces_x * time;
  velocity_y += forces_y * time;
  velocity_z += forces_z * time;
}