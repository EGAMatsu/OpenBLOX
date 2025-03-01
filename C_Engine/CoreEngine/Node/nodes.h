/*
    OpenBLOX nodes
*/

#ifndef _NODES_H_
#define _NODES_H_



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
#define PI 3.1415f

class CFrame {
    public:
        float X,Y,Z,R00,R01,R02,R10,R11,R12,R20,R21,R22;

    /*vec3 toEulerAngles()
    {
        vec3 ret;

        float T1 = atan2(R21, R22);
        float C2 = sqrt(R00*R00 + R10*R10);
        float T2 = atan2(-R20, C2);
        float S1 = sin(T1);
        float C1 = cos(T1);
        float T3 = atan2(S1*R02 - C1*R01, C1*R11 - S1*R12);

        ret.x = -T1;
        ret.y = -T2;
        ret.z = -T3;
    
        return ret;
    }*/

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

