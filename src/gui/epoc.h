#ifndef EPOC_H
#define EPOC_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QThread>

#include "glviewer.h"
#include "glcolor.h"
#include "mesh.h"
#include "driver/libepoc.h"

using namespace std;

class glviewer;
class epoc : public QThread
{
public:
    static epoc * getInstance ();
    inline epoc() { read = true; }

    inline void setmesh     (mesh * glm)     { this->glm = glm; }
    inline void setglviewer (glviewer * glv) { this->glv = glv; }
    void run();

private:
    bool read;
    mesh * glm;
    glviewer * glv;

};

#endif // EPOC_H
