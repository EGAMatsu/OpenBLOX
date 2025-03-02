/*
    OpenBLOX DS OpenGL Functions
*/

#include <GL/gl.h>
#include <GL/glu.h>

#define defaultWidth 640
#define defaultHeight 480
SDL_Event event;

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
    SDL_GL_SwapBuffers();
}

void start3DFrame() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isGameRunning = 0;
        }
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST); 
}

void SDL_Initialization() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_Surface* screen = SDL_SetVideoMode(defaultWidth, defaultHeight, 32, SDL_OPENGL);
    if (!screen) {
        fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
        SDL_Quit();
    }
}

void glSetColor(int r, int g, int b) {
    glColor3f(r/255.0f,g/255.0f,b/255.0f);
}