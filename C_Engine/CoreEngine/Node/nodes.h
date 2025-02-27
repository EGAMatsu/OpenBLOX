/*
    OpenBLOX nodes
*/

#ifndef _NODES_H_
#define _NODES_H_

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
    float x, y, z, rx, ry, rz, sx, sy, sz;
};

#endif // _NODES_H_

