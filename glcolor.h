#ifndef GLCOLOR_H
#define GLCOLOR_H

#include <QGLViewer/qglviewer.h>

class glcolor
{
public:
    GLfloat color[4];
    inline glcolor() {}
    inline glcolor(GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
        this->color[0] = r;
        this->color[1] = g;
        this->color[2] = b;
        this->color[3] = a;
    }
};

#endif // GLCOLOR_H
