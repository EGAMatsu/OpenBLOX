/*
    OpenBLOX nodes
*/

// Base Node
typedef struct node {
    char name[128];
    char type[128];
    struct node *parent;
} Node;

// Part
typedef struct part {
    Node node;
    int color;
    float x, y, z, rx, ry, rz, sx, sy, sz;
} Part;