/*
    OpenBLOX OpenGL globals
*/

float distanceBetweenPoints(float x1, float y1, float z1, float x2, float y2, float z2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float dz = z2 - z1;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

float averageSize(float x, float y, float z) {
    return (x + y + z) / 3.0f;
}

float cube_vert[] = {
    // Front face
    -0.5, -0.5,  0.5,
     0.5, -0.5,  0.5,
     0.5,  0.5,  0.5,
    -0.5,  0.5,  0.5,
    
    // Back face
    -0.5, -0.5, -0.5,
    -0.5,  0.5, -0.5,
     0.5,  0.5, -0.5,
     0.5, -0.5, -0.5,
    
    // Left face
    -0.5, -0.5, -0.5,
    -0.5, -0.5,  0.5,
    -0.5,  0.5,  0.5,
    -0.5,  0.5, -0.5,
    
    // Right face
     0.5, -0.5, -0.5,
     0.5,  0.5, -0.5,
     0.5,  0.5,  0.5,
     0.5, -0.5,  0.5,
    
    // Top face
    -0.5,  0.5, -0.5,
    -0.5,  0.5,  0.5,
     0.5,  0.5,  0.5,
     0.5,  0.5, -0.5,
    
    // Bottom face
    -0.5, -0.5, -0.5,
     0.5, -0.5, -0.5,
     0.5, -0.5,  0.5,
    -0.5, -0.5,  0.5,
};

unsigned char cube_inds[] = {
    // Front face
    0, 1, 2, 2, 3, 0,
    // Back face
    4, 5, 6, 6, 7, 4,
    // Left face
    8, 9, 10, 10, 11, 8,
    // Right face
    12, 13, 14, 14, 15, 12,
    // Top face
    16, 17, 18, 18, 19, 16,
    // Bottom face
    20, 21, 22, 22, 23, 20,
};

float cube_norm[] = {
    // Front face
    0.0,  0.0,  1.0,
    0.0,  0.0,  1.0,
    0.0,  0.0,  1.0,
    0.0,  0.0,  1.0,

    // Back face
    0.0,  0.0, -1.0,
    0.0,  0.0, -1.0,
    0.0,  0.0, -1.0,
    0.0,  0.0, -1.0,

    // Left face
   -1.0,  0.0,  0.0,
   -1.0,  0.0,  0.0,
   -1.0,  0.0,  0.0,
   -1.0,  0.0,  0.0,

    // Right face
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,

    // Top face
    0.0,  1.0,  0.0,
    0.0,  1.0,  0.0,
    0.0,  1.0,  0.0,
    0.0,  1.0,  0.0,

    // Bottom face
    0.0, -1.0,  0.0,
    0.0, -1.0,  0.0,
    0.0, -1.0,  0.0,
    0.0, -1.0,  0.0,
};

float clr_multi[] = {
    0.9, 0.7, 0.8, 0.8, 1, 0.5
};

void scale_rotate_translate(float xs, float ys, float zs, float rx, float ry, float rz, float tx, float ty, float tz) {
    // Use appropriate gl functions for transformations
    glTranslatef(tx, ty, tz);
    glRotatef(rx, 1.0, 0.0, 0.0);
    glRotatef(ry, 0.0, 1.0, 0.0);
    glRotatef(rz, 0.0, 0.0, 1.0);
    glScalef(xs, ys, zs);
}

void render_cube(int colorIndex, float transparency) {
    int color = colorGrab(colorIndex, 0);
    int r = getHex_value(color, 0);
    int g = getHex_value(color, 1);
    int b = getHex_value(color, 2);
    
    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < sizeof(cube_inds) / sizeof(cube_inds[0]); i += 4) {
        for (unsigned int j = 0; j < 4; ++j) {
            unsigned int index = cube_inds[i + j];
            unsigned int indVr = index * 3;
            unsigned int indexL = cube_inds[i + j] / 4;
            
            glSetColor(r, g, b, transparency);
            glNormal3f(cube_norm[indVr + 1], cube_norm[indVr + 2], cube_norm[indVr]);
            glVertex3f(cube_vert[indVr + 1], cube_vert[indVr + 2], cube_vert[indVr]); 
        }
    }
    glEnd();
}

void render_cube_transform(float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, int color, float transparency) {
    if ((distanceBetweenPoints(-camera_x, -camera_y, -camera_z, x,y,z) < maxPartDist) || (averageSize(sx,sy,sz) > 16)) {
        pushMatrix();
            scale_rotate_translate(sx, sy, sz, rx, ry, rz, x, y, z);
            render_cube(color, transparency);
        popMatrix();
    }
}

void render_cube_cf(CFrame cf, vec3 size, int color, float transparency)
{
    vec3 p = cf.position();
    vec3 r = cf.toEulerAngles();
    render_cube_transform(p.x, p.y, p.z, r.x, r.y, r.z, abs(size.x), abs(size.y), abs(size.z), color, transparency);
}

