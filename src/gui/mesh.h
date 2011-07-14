// ---------------------------------------------------------
// mesh Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2008 Tamy Boubekeur.
// All rights reserved.
// ---------------------------------------------------------

#ifndef MESH_H
#define MESH_H

#if __APPLE__
#	include <GLUT/glut.h>
#else
#	include <GL/glut.h>
#endif

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

#include "vertex.h"
#include "triangle.h"
#include "edge.h"
#include "glcolor.h"
#include "param.h"

class mesh {
public:
    static mesh * getInstance ();
    inline mesh () {
        prm = param::getInstance();
        glc = glcolor::getInstance();
        loadmesh();
    }
    inline virtual ~mesh () {}
    std::vector<vertex> & getVertices () { return vertices; }
    const std::vector<vertex> & getVertices () const { return vertices; }
    std::vector<triangle> & getTriangles () { return triangles; }
    const std::vector<triangle> & getTriangles () const { return triangles; }

    inline void setprm(param * prm) { this->prm = prm; glc->set_prm(prm); }

    void clear ();
    void recomputeSmoothVertexNormals (unsigned int weight);
    void computeTriangleNormals (std::vector<vec3Df> & triangleNormals);    
    void renderGL() const;
    void loadOFF (const std::string & filename);

    inline void loadmesh(){
        switch(prm->get_mesh()){
        case 0:
            loadOFF("models/brain.off");
            break;
        case 1:
            loadOFF("models/brainL.off");
            break;
        case 2:
            loadOFF("models/brainH.off");
            break;
        }
    }

    class Exception {
    private: 
        std::string msg;
    public:
       Exception (const std::string & msg) : msg ("[mesh Exception]" + msg) {}
        virtual ~Exception () {}
        inline const std::string & getMessage () const { return msg; }
    };

private:
    glcolor * glc;
    param * prm;
    std::vector<vertex> vertices;
    std::vector<triangle> triangles;
};

#endif // MESH_H
