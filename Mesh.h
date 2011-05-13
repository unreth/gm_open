// ---------------------------------------------------------
// Mesh Class
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

#include "Vertex.h"
#include "Triangle.h"
#include "Edge.h"

class Mesh {
public:
    static Mesh * getInstance ();
    inline Mesh () {
        loadOFF("models/brain.off");
    }
    inline Mesh (const std::vector<Vertex> & v) 
        : vertices (v) {}
    inline Mesh (const std::vector<Vertex> & v, 
                 const std::vector<Triangle> & t) 
        : vertices (v), triangles (t)  {}
    inline Mesh (const Mesh & mesh) 
        : vertices (mesh.vertices), 
          triangles (mesh.triangles) {}
        
    inline virtual ~Mesh () {}
    std::vector<Vertex> & getVertices () { return vertices; }
    const std::vector<Vertex> & getVertices () const { return vertices; }
    std::vector<Triangle> & getTriangles () { return triangles; }
    const std::vector<Triangle> & getTriangles () const { return triangles; }
    void clear ();
    void clearGeometry ();
    void clearTopology ();
    void unmarkAllVertices ();
    void recomputeSmoothVertexNormals (unsigned int weight);
    void computeTriangleNormals (std::vector<Vec3Df> & triangleNormals);  
    void collectOneRing (std::vector<std::vector<unsigned int> > & oneRing) const;
    void collectOrderedOneRing (std::vector<std::vector<unsigned int> > & oneRing) const;
    void computeDualEdgeMap (EdgeMapIndex & dualVMap1, EdgeMapIndex & dualVMap2);
    void markBorderEdges (EdgeMapIndex & edgeMap);
    
    void renderGL() const;
    void loadOFF (const std::string & filename);
    class Exception {
    private: 
        std::string msg;
    public:
        Exception (const std::string & msg) : msg ("[Mesh Exception]" + msg) {}
        virtual ~Exception () {}
        inline const std::string & getMessage () const { return msg; }
    };

private:
    std::vector<Vertex> vertices;
    std::vector<Triangle> triangles;
};

#endif // MESH_H