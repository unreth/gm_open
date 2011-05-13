// *********************************************************
// OpenGL Viewer Class, based on LibQGLViewer, compatible
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

#include "Mesh.h"

class GLViewer : public QGLViewer  {
    Q_OBJECT
public:
    
    typedef enum {Flat=0, Smooth=1} RenderingMode;
    
    GLViewer ();
    virtual ~GLViewer ();
    
    inline int getRenderingMode () const { return renderingMode; }
    
    class Exception  {
    public:
        Exception (const std::string & msg) : message ("[GLViewer]"+msg) {}
        virtual ~Exception () {}
        const std::string & getMessage () const { return message; }
    private:
        std::string message;
    }; 
     
public slots :
    void setRenderingMode (bool m);
    
protected :
    void init();
    void draw ();

    virtual void keyPressEvent ( QKeyEvent * event );
    virtual void keyReleaseEvent ( QKeyEvent * event );

private:
    RenderingMode renderingMode; 
};

#endif // GLVIEWER_H