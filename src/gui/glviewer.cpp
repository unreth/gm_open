#include "glviewer.h"

using namespace std;

static const GLuint OpenGLLightID[] = {GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7};

glviewer::glviewer () : QGLViewer () {
    this->prm = param::getInstance();
    renderingMode = Smooth;
}
glviewer::~glviewer () { }

void glviewer::keyPressEvent (QKeyEvent * /*event*/)   {}
void glviewer::keyReleaseEvent (QKeyEvent * /*event*/) {}

void glviewer::init() {
    //initialization

    //background
    glClearColor ((int)(prm->get_bg()[0]*255.),(int)(prm->get_bg()[1]*255.),(int)(prm->get_bg()[2]*255.), 0.);

    glDepthFunc (GL_LEQUAL);

    //smooth
    glHint (GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable (GL_POINT_SMOOTH);

    glLoadIdentity ();

    //two side faces
//    glDisable(GL_CULL_FACE);
    glEnable(GL_CULL_FACE); glCullFace (GL_BACK);

    //lighting
    if(prm->get_lighting()) glEnable (GL_LIGHTING);
    else                    glDisable(GL_LIGHTING);

    //alpha
    glEnable (GL_COLOR_MATERIAL);
    glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    vec3Df c;
    setSceneCenter (qglviewer::Vec (c[0], c[1], c[2]));
    setSceneRadius (5);
    showEntireScene ();
    startAnimation();   //automatic update!
}

void glviewer::draw () {
    mesh * mesh = mesh::getInstance();
    mesh->renderGL();
}
