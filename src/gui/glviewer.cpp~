#include "GLViewer.h"

using namespace std;

static const GLuint OpenGLLightID[] = {GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7};

GLViewer::GLViewer () : QGLViewer () {
    renderingMode = Smooth;
}

GLViewer::~GLViewer () {
}


void GLViewer::setRenderingMode (bool m) {
    renderingMode = static_cast<RenderingMode>((int)m);
    updateGL ();
}

void GLViewer::keyPressEvent (QKeyEvent * /*event*/) {
    
}

void GLViewer::keyReleaseEvent (QKeyEvent * /*event*/) {

}

void GLViewer::init() {
    glClearColor (0.f, 0.f, 0.f, 0.0);
    glCullFace (GL_BACK);
    glEnable (GL_CULL_FACE);
    glDepthFunc (GL_LEQUAL);
    glHint (GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable (GL_POINT_SMOOTH);

    glLoadIdentity ();
    
    glEnable (GL_LIGHTING);
    glEnable (GL_COLOR_MATERIAL);

    Vec3Df c(-0.12808,-0.036755,0);
    float r = 4.74445;

    setSceneCenter (qglviewer::Vec (c[0], c[1], c[2]));
    setSceneRadius (r);
    showEntireScene ();
}

void GLViewer::draw () {
    Mesh * mesh = Mesh::getInstance();
    mesh->renderGL();
}



