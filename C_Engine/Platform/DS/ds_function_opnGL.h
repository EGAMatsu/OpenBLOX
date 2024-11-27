/*
    OpenBLOX DS OpenGL Functions
*/

void initOpenGL() {
    // Set video modes
    videoSetMode(MODE_0_3D);
    vramSetBankA(VRAM_A_TEXTURE);

    // Start GL
    glInit();
    glEnable(GL_TEXTURE_2D);
    glClearColor(0, 0, 0, 31); // Background must be opaque for antialiasing to work
    glClearPolyID(63); // Background must have a unique polygon ID for antialiasing to work
    glClearDepth(0x7FFF);
    glViewport(0, 0, 255, 191);
}


// Use perspective projection
void perspectiveModeGL() {
    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 256.0 / 192.0, 0.1, 2048); // Adjusted to match your previous example

    gluLookAt(  0.0, 0.0, 0.0,      // Camera position
                0.0, 0.0, 1.0,      // Look at
                0.0, 1.0, 0.0);     // Up direction
    
    // Configure the polygon format
    glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
}


void pushMatrix() {
    glPushMatrix();
}

void popMatrix() {
    glPopMatrix(1);
}

void endFrame() {
    glPopMatrix(1);
    glFlush(0);
    swiWaitForVBlank();
}

void start3DFrame() {
    glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
    glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);
}