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

class mesh {
public:
    static mesh * getInstance ();
    inline mesh () {
        loadOFF("../../models/brain.off");
    }
    inline mesh (const std::vector<vertex> & v) 
        : vertices (v) {}
    inline mesh (const std::vector<vertex> & v, 
                 const std::vector<triangle> & t) 
        : vertices (v), triangles (t)  {}
    inline mesh (const mesh & mesh) 
        : vertices (mesh.vertices), 
          triangles (mesh.triangles) {}
        
    inline virtual ~mesh () {}
    std::vector<vertex> & getVertices () { return vertices; }
    const std::vector<vertex> & getVertices () const { return vertices; }
    std::vector<triangle> & getTriangles () { return triangles; }
    const std::vector<triangle> & getTriangles () const { return triangles; }
    void clear ();
    void clearGeometry ();
    void clearTopology ();
    void unmarkAllVertices ();
    void recomputeSmoothVertexNormals (unsigned int weight);
    void computeTriangleNormals (std::vector<vec3Df> & triangleNormals);  
    void collectOneRing (std::vector<std::vector<unsigned int> > & oneRing) const;
    void collectOrderedOneRing (std::vector<std::vector<unsigned int> > & oneRing) const;
    void computeDualEdgeMap (edgeMapIndex & dualVMap1, edgeMapIndex & dualVMap2);
    void markBorderEdges (edgeMapIndex & edgeMap);
    
    void renderGL() const;
    void loadOFF (const std::string & filename);
    class Exception {
    private: 
        std::string msg;
    public:
        Exception (const std::string & msg) : msg ("[mesh Exception]" + msg) {}
        virtual ~Exception () {}
        inline const std::string & getMessage () const { return msg; }
    };

private:
    std::vector<vertex> vertices;
    std::vector<triangle> triangles;
};

#endif // MESH_H
