#include "glviewer.h"

using namespace std;

static const GLuint OpenGLLightID[] = {GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7};

glviewer::glviewer () : QGLViewer () {
    renderingMode = Smooth;
}

glviewer::~glviewer () {
}


void glviewer::setRenderingMode (bool m) {
    renderingMode = static_cast<RenderingMode>((int)m);
    updateGL ();
}

void glviewer::keyPressEvent (QKeyEvent * /*event*/)   {
//    camera()->frame()->rotate(1,1,1,1);
}
void glviewer::keyReleaseEvent (QKeyEvent * /*event*/) {}

void glviewer::init() {
    glClearColor (0.f, 0.f, 0.f, 0.0);
    glCullFace (GL_BACK);
    glEnable (GL_CULL_FACE);
    glDepthFunc (GL_LEQUAL);
    glHint (GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable (GL_POINT_SMOOTH);

    glLoadIdentity ();
    
    glEnable (GL_LIGHTING);
    glEnable (GL_COLOR_MATERIAL);

    vec3Df c(-0.12808,-0.036755,0);
    float r = 4.74445;

    setSceneCenter (qglviewer::Vec (c[0], c[1], c[2]));
    setSceneRadius (r);
    showEntireScene ();
}

void glviewer::draw () {
    mesh * mesh = mesh::getInstance();
    mesh->renderGL();
}



