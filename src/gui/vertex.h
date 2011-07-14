// *********************************************************
// vertex Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2008 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <QGLViewer/qglviewer.h>

#include "vec3D.h"
#include "glcolor.h"

#define PI 3.141592

class vertex {
public:
    inline vertex () :                                          pos (vec3Df (0.0,0.0,0.0)), normal (vec3Df (0.0, 0.0, 1.0)), phi(0), theta(0)           {}
    inline vertex (const vec3Df & pos) :                        pos (pos),                  normal (vec3Df (0.0, 0.0, 1.0)), phi(0), theta(0)           {}
    inline vertex (const vec3Df & pos, const vec3Df & normal) : pos (pos),                  normal (normal),                 phi(0), theta(0)           {}
    inline vertex (const vertex & v) :                          pos (v.pos),                normal (v.normal),               phi(v.phi), theta(v.theta) {}
    inline virtual ~vertex () {}

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
            else                        phi = PI/2;
        }
        phi *= 180/PI;
    }
    inline void setcolor(float theta, float phi) {
        //sets its color from its angular position
        glc = glcolor::getInstance();
        this->color = glc->getColor(theta,phi,alfa,sensor);
    }

    inline vertex & operator= (const vertex & vertex) {
        pos = vertex.pos;
        normal = vertex.normal;
//        marked = vertex.marked;
//        id = -1;
        color = vertex.color;
        phi = vertex.phi;
        theta = vertex.theta;
        return (*this);
    }
    inline const GLfloat & getR() const { return this->color[0]; }  //red
    inline const GLfloat & getG() const { return this->color[1]; }  //green
    inline const GLfloat & getB() const { return this->color[2]; }  //blue
    inline const GLfloat & getA() const { return this->alfa; }      //alfa transparency
    inline bool getSensor() { return this->sensor; }                //is a sensor
    inline const GLfloat & getTheta() const { return this->theta; }
    inline const GLfloat & getPhi() const { return this->phi; }

    inline const vec3Df & getPos () const { return pos; }
    inline const vec3Df & getNormal () const { return normal; }
    inline void setPos (const vec3Df & newPos) { pos = newPos; }
    inline void setNormal (const vec3Df & newNormal) { normal = newNormal; }
    inline bool operator== (const vertex & v) { return (v.pos == pos && v.normal == normal); }

    static void normalizeNormals (std::vector<vertex> & vertices);


private:
    glcolor * glc;
    vec3Df pos;
    vec3Df normal;

    vec3Df color;
    float alfa;
    bool sensor;

    float phi;
    float theta;
};

extern std::ostream & operator<< (std::ostream & output, const vertex & v);

#endif // VERTEX_H
