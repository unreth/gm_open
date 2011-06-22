#ifndef EPOC_H
#define EPOC_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QThread>
#include <QGLViewer/quaternion.h>

#include "glcolor.h"
#include "driver/libepoc.h"
#include "glviewer.h"

using namespace std;

class glviewer;
class epoc : public QThread
{
public:
    static epoc * getInstance ();
    inline epoc() { read = true; }

    inline void setglv(glviewer * glv) { this->glv = glv; }
    void run();

private:
    bool read;
    glviewer * glv;
};

#endif // EPOC_H
