/*
    OpenBLOX nodes
*/

#ifndef _NODES_H_
#define _NODES_H_

class vec3 {
    public:
        float x, y, z;
};

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

