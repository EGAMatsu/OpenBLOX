/*
    OpenBLOX nodes
*/

#ifndef _NODES_H_
#define _NODES_H_

class vec3 {
    public:
        float x, y, z;
};
void set_vec3(vec3* vector3, float x, float y, float z) {
    vector3->x = x;
    vector3->y = y;
    vector3->z = z;
}

// Base Node
class Node {
public:
    char name[128];
    char type[128];
    Node* parent;
};

// Part
class Part : public Node {
public:
    int color;
    vec3 position, scale, rotation;
};

// SpawnLocation
class SpawnLocation : public Part {
public:
    int teamColor;
};

#endif // _NODES_H_

