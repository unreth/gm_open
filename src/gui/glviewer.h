// *********************************************************
// OpenGL Viewer Class, based on LibQglviewer, compatible
// with most hardware (OpenGL 1.2).
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2010 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#ifndef GLVIEWER_H
#define GLVIEWER_H

#include <QGLViewer/qglviewer.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <string>

#include "mesh.h"
#include "epoc.h"

class glviewer : public QGLViewer  {
    Q_OBJECT
public:
    
    typedef enum {Flat=0, Smooth=1} RenderingMode;
    
    glviewer ();
    virtual ~glviewer ();

    inline void reinit() { init(); }

    //class Exception
    class Exception  {
    public:
        Exception (const std::string & msg) : message ("[glviewer]"+msg) {}
        virtual ~Exception () {}
        const std::string & getMessage () const { return message; }
    private:
        std::string message;
    };

public slots:
    inline void set_lighting(bool l) {
        if(l)   glEnable  (GL_LIGHTING);
        else    glDisable (GL_LIGHTING);
    }

protected :
    void init();
    void draw ();

    virtual void keyPressEvent ( QKeyEvent * event );
    virtual void keyReleaseEvent ( QKeyEvent * event );

private:
    RenderingMode renderingMode;
    param * prm;
};

#endif // GLVIEWER_H
