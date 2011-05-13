// *********************************************************
// Vertex Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2008 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <QGLViewer/qglviewer.h>

#include "Vec3D.h"

#define PI 3.141592

class Vertex {
public:
    inline Vertex () :                                          pos (Vec3Df (0.0,0.0,0.0)), normal (Vec3Df (0.0, 0.0, 1.0)), marked (false),    id (-1) { initcolor(); calcangles(); }
    inline Vertex (const Vec3Df & pos) :                        pos (pos),                  normal (Vec3Df (0.0, 0.0, 1.0)), marked (false),    id (-1) { initcolor(); calcangles(); }
    inline Vertex (const Vec3Df & pos, const Vec3Df & normal) : pos (pos),                  normal (normal),                 marked (false),    id (-1) { initcolor(); calcangles(); }
    inline Vertex (const Vertex & v) :                          pos (v.pos),                normal (v.normal),               marked (v.marked), id (-1) { initcolor(); calcangles(); }
    inline virtual ~Vertex () {}

    inline void initcolor() {
        //color
        color[0] = 1.f;
        color[1] = 1.f;
        color[2] = 1.f;
    }
    inline void calcangles () {
        //theta
        if(pos[2]>0)                    theta = atan(sqrt(pos[0]*pos[0] + pos[1]*pos[1])/pos[2]);
        else if(pos[2]<0)               theta = atan(sqrt(pos[0]*pos[0] + pos[1]*pos[1])/pos[2]) + PI;
        else                            theta = PI/2;
        theta *= 180/PI;
        //phi
        if(pos[0]>0){
            if(pos[1]<0)                phi = atan(pos[1]/pos[0]) + 2*PI;
            else                        phi = atan(pos[1]/pos[0]);
        }
        else if(pos[0]<0)               phi = atan(pos[1]/pos[0]) + PI;
        else{
            if(pos[1]<0)                phi = -PI/2;
            else                        phi = -PI/2;
        }
    }

    inline Vertex & operator= (const Vertex & vertex) {
        pos = vertex.pos;
        normal = vertex.normal;
        marked = vertex.marked;
        id = -1;
        return (*this);
    }
    inline const GLfloat & getColor0() const { return color[0]; }
    inline const GLfloat & getColor1() const { return color[1]; }
    inline const GLfloat & getColor2() const { return color[2]; }
    inline const Vec3Df & getPos () const { return pos; }
    inline const Vec3Df & getNormal () const { return normal; }  
    inline bool isMarked () const { return marked; }
    inline int getId () const { return id; }
    inline void setPos (const Vec3Df & newPos) { pos = newPos; }
    inline void setNormal (const Vec3Df & newNormal) { normal = newNormal; }
    inline void mark () { marked = true; }
    inline void unmark () { marked = false; }
    inline void setId (int newId) { id = newId; } 
    inline bool operator== (const Vertex & v) { return (v.pos == pos && v.normal == normal); }

    void interpolate (const Vertex & u, const Vertex & v, float alpha = 0.5);
    static void computeAveragePosAndRadius (std::vector<Vertex> & vertices, Vec3Df & center, float & radius);
    static void scaleToUnitBox (std::vector<Vertex> & vertices, Vec3Df & center, float & scaleToUnitBox);
    static void normalizeNormals (std::vector<Vertex> & vertices);

private:
    GLfloat color[3];
    Vec3Df pos;
    Vec3Df normal;
    bool marked;
    int id;

    float phi;
    float theta;
};

extern std::ostream & operator<< (std::ostream & output, const Vertex & v);

#endif // VERTEX_H
