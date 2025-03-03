/*
    OpenBLOX DS OpenGL Functions
*/

#include <GL/gl.h>
#include <GL/glu.h>

#define defaultWidth 640
#define defaultHeight 480
#ifndef WII_BUILD
    SDL_Event event;
#endif

void SDL_Initialization();
void initOpenGL() {
    SDL_Initialization();
    
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glViewport(0, 0, defaultWidth, defaultHeight);
}

void perspectiveModeGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, defaultWidth / defaultHeight, 0.1, 1024.0);

    gluLookAt(  0.0, 0.0, 0.0,      // Camera position
                0.0, 0.0, 1.0,      // Look at
                0.0, 1.0, 0.0);     // Up direction
    
    // Configure the polygon format
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
}


void pushMatrix() {
    glPushMatrix();
}

void popMatrix() {
    glPopMatrix();
}

void endFrame() {
    glPopMatrix();
    glFlush();
    
    #ifndef WII_BUILD
        SDL_GL_SwapBuffers();
    #endif
}

void start3DFrame() {
    #ifndef WII_BUILD
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isGameRunning = 0;
            }
        }
    #endif

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_CULL_FACE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST); 

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void SDL_Initialization() {
    #ifndef WII_BUILD
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        }

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_Surface* screen = SDL_SetVideoMode(defaultWidth, defaultHeight, 32, SDL_OPENGL);
        if (!screen) {
            fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
            SDL_Quit();
        }
    #endif
}

void glSetColor(int r, int g, int b, float transparency) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float rr = (r / 255.0f) * 0.75f;
    float gg = (g / 255.0f) * 0.75f;
    float bb = (b / 255.0f) * 0.75f;

    float rrr = r / 255.0f;
    float ggg = g / 255.0f;
    float bbb = b / 255.0f;
    glColor4f(rrr,ggg,bbb, 1.0f-transparency);

    GLfloat a[] = {rrr, ggg, bbb, 1.0f - transparency};
    GLfloat d[] = {rrr, ggg, bbb, 1.0f - transparency};
    GLfloat s[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat e[] = {0.0f, 0.0f, 0.0f, 1.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, a);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, d);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, e);

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.9f);
}

void setupLighting() {
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    pushMatrix();
        GLfloat lightColor[] = {2.0f, 2.0f, 2.0f, 1.0f};
        GLfloat lightPos[] = {1.0f, 1.0f, 1.0f, 0.0f}; 

        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    popMatrix();
}