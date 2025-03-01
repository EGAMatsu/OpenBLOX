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

// Base Node
class Node {
public:
    virtual ~Node() {}
    char name[64];
    char type[32];
    Node* parent;
};

// Part
class Part : public Node {
public:
    int color = 2;
    int shape; // Maybe make -1 force the engine to find a SpecialMesh?
    vec3 position, scale, rotation;
    void render() {
        vec3 p, s, r;
        p = this->position;
        s = this->scale;
        r = this->rotation;
        render_cube_transform(p.x,p.y,p.z, s.x,s.y,s.z, r.x,r.y,r.z, this->color);
    }
};

// SpawnLocation
class SpawnLocation : public Part {
public:
    int teamColor = 2;
};

// Shitty world render function, will be slow, but will hopefully work if shit doesn't break.
void renderWorld(Node *world) {
    int length = sizeof(world) / sizeof(Node); // Might work.
    for (int i = 0; i < length; i++) {
        Node* node = &world[i];
        
        // Attempt Cast.
        Part* part = dynamic_cast<Part*>(node);
        if (part) {
            part->render(); // Part exists, render (TODO: Make optimized.)
        }
    }
}

#endif // _NODES_H_

