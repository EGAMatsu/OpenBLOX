/*Part Class*/
#include <nds.h>
#include <filesystem.h>
#include <fat.h>
#include <math.h>
#include <cstdio>
#include <vector>
#include <time.h>

void glVertex3(float x,float y,float z);
void drawBlock(float x, float y, float z, float width, float height, float depth, int r, int g, int b, float alpha, bool doCull);

class Object {
	public:
		const char *name;  // Attribute (string variable)
		int id;
		int parent_id;
		int color_r, color_g, color_b, brickColor;
		
		void calculateBrickColor(int value);
};

class Part : public Object {
  public:
	float pos_x, pos_y, pos_z, scale_width, scale_height, scale_depth;
	float r00, r01, r02, r10, r11, r12, r20, r21, r22;
	int shape;
	float transparency;
	bool canCollide = false;
	bool isAnchored;
	bool canInteract = true;
	bool doesExist = true;
	bool doCull = true;
	
	/*Physics*/
	float velocity_x, velocity_y, velocity_z, forces_x, forces_y, forces_z;
	
	/*The Functions*/
	void update(float time);  // declare the update function
	void draw();
	float getDistanceFromPlayer(float player_x, float player_y, float player_z);
	bool isObstructed(float x, float y, float z, float radius);
};

class SpawnLocation : public Part {
	public:
		int teamColor = -1;
};

class Script : public Object {
	public:
		bool isEnabled = true;
		const char *source;
};

class Model : public Object {
	public:
		float pos_x, pos_y, pos_z, scale_width, scale_height, scale_depth;
		float r00, r01, r02, r10, r11, r12, r20, r21, r22;
		const char *name;
};

class Workspace : public Object {
	
};

class Humanoid : public Object {
	public:
		/* Health */
		int health = 100;
		int maxHealth = 100;
		
		/* Action */
		bool isOnGround = false;
		bool jump = false;
		bool sit = false;
		
		/* Movement */
		Part *walkToPart = nullptr;
		float pos_x, pos_y, pos_z;
		float gravity = 0.25;
		float jumpForce = 5;
		
		/* Facing Direction V3 */
		float facingDirection_x = 0;
		float facingDirection_y = 0;
		float facingDirection_z = 0;
		
		/* Target Point V3 */
		float targetPoint_x = 0;
		float targetPoint_y = 0;
		float targetPoint_z = 0;
		
		/* Walk Direction V3 */
		float walkDirection_x = 0;
		float walkDirection_y = 0;
		float walkDirection_z = 0;
		
		/* Walk Velocity Rel. V3 */
		float walkVelocityRelative_x = 0;
		float walkVelocityRelative_y = 0;
		float walkVelocityRelative_z = 0;
		
		/* Walk-To-Point V3 */
		float walkToPoint_x = 0;
		float walkToPoint_y = 0;
		float walkToPoint_z = 0;
};

class Player : public Humanoid {
	public:
		int teamColor;
		float directionFacing_x = 0;
		void Input();
		void Update(std::vector<Part> parts, int partCount);
		void Render();
};