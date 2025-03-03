/*
    OpenBLOX nodes
*/

#ifndef _NODES_H_
#define _NODES_H_

void render_cube_transform(float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, int color); 

class vec3 {
    public:
        float x, y, z;
}; typedef vec3 Vector3;
void set_vec3(vec3* vector3, float x, float y, float z) {
    vector3->x = x;
    vector3->y = y;
    vector3->z = z;
}

#include <cmath>

class CFrame {
    public:
        float X,Y,Z,R00,R01,R02,R10,R11,R12,R20,R21,R22;

    vec3 toEulerAngles()
    {
        vec3 ret;
       
        // Extract angles assuming YXZ rotation order
        float sy = -R20;
    
        if (fabs(sy) < 1.0f) // Standard case
        {
            ret.x = atan2(R21, R22) * (180.0 / M_PI);   // Roll
            ret.y = asin(sy)        * (180.0 / M_PI);   // Pitch
            ret.z = atan2(R10, R00) * (180.0 / M_PI);   // Yaw
        }
        else // Gimbal lock case
        {
            ret.x = 0; // Roll is undefined, set to zero
            ret.y = ((sy > 0) ? M_PI / 2 : -M_PI / 2) * (180.0 / M_PI); // ±90 degrees
            ret.z = atan2(-R01, R11)                  * (180.0 / M_PI); // Yaw
        }

        return ret; 
    }

    vec3 position()
    {
        vec3 ret;

        ret.x = X;
        ret.y = Y;
        ret.z = Z;

        return ret;
    }

};
typedef CFrame CoordinateFrame;

void render_cube_cf(CFrame cf, vec3 size, int color);

#include <vector>

// Base Node
class Node {
public:
    virtual ~Node() {}
    char name[64];
    char type[32];
    Node* parent;
    std::vector<Node*> children;

    bool locked = false;
    bool anchored = true;

    void SetParent(Node *newParent)
    {
        parent = newParent;
        newParent->children.push_back(this);
    }
};

// Part
class Part : public Node {
public:
    int color = 2;
    int shape; // Maybe make -1 force the engine to find a SpecialMesh?
    vec3 scale;
    CFrame cf;
    void render() {
        render_cube_cf(cf, scale, color);
    }
};

// SpawnLocation
class SpawnLocation : public Part {
public:
    int teamColor = 2;
};

// Shitty world render function, will be slow, but will hopefully work if shit doesn't break.
void renderWorld(Node *world) {
    for (int i = 0; i < world->children.size(); i++) {
        Node* node = world->children[i];
        
        // Attempt Cast.
        Part* part = dynamic_cast<Part*>(node);
        if (part != nullptr) {
            //printf("Render part\n");
            part->render(); // Part exists, render (TODO: Make optimized.)
        }

        renderWorld(node);
    }
}

#endif // _NODES_H_

