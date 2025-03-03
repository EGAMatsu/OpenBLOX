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

    glClearColor(0, 0, 0, 31);
    glClearPolyID(63);
    
    glClearDepth(0x7FFF);
    glViewport(0, 0, 255, 191);

    glSetToonTableRange( 0, 15, RGB15(8,8,8) );
	glSetToonTableRange( 16, 31, RGB15(24,24,24) );
    glEnable(GL_ANTIALIAS); 
}


// Use perspective projection
void perspectiveModeGL() {
    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 256.0 / 192.0, 0.1, 1024);

    gluLookAt(  0.0, 0.0, 0.0,      // Camera position
                0.0, 0.0, 1.0,      // Look at
                0.0, 1.0, 0.0);     // Up direction

    // Configure the polygon format
    glPolyFmt(POLY_ALPHA(31) | POLY_CULL_BACK | POLY_FORMAT_LIGHT0);

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
    popMatrix();
    glFlush(0);
    
    swiWaitForVBlank();
}

void start3DFrame() {
    perspectiveModeGL();
    glPushMatrix();
}

void glSetColor(int r, int g, int b, float transparency) {
    glColor3b(r,g,b);
    int rr, gg, bb;
    rr = int(r*0.125);
    gg = int(g*0.125);
    bb = int(b*0.125);
    glMaterialf(GL_AMBIENT, RGB15(rr/2,gg/2,bb/2));
    glMaterialf(GL_DIFFUSE, RGB15(rr,gg,bb));
    glMaterialf(GL_SPECULAR, RGB15(16,16,16));
    glMaterialf(GL_EMISSION, RGB15(0,0,0));
}

void setupLighting() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    pushMatrix();
        glLight(0, RGB15(31,31,31), floattov10(1.0), floattov10(-1.0), floattov10(1.0));
    popMatrix();
}