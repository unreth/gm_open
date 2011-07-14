// ---------------------------------------------------------
// mesh Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2008 Tamy Boubekeur.
// All rights reserved.
// ---------------------------------------------------------

#include "mesh.h"

using namespace std;

static mesh * meshinstance = NULL;

mesh * mesh::getInstance () {
    if (meshinstance == NULL){
        meshinstance = new mesh ();
    }
    return meshinstance;
}

void mesh::clear () {
    vertices.clear ();
    triangles.clear ();
}

void mesh::computeTriangleNormals (vector<vec3Df> & triangleNormals) {
    for (vector<triangle>::const_iterator it = triangles.begin ();
         it != triangles.end ();
         it++) {
        vec3Df e01 (vertices[it->getVertex (1)].getPos () - vertices[it->getVertex (0)].getPos ());
        vec3Df e02 (vertices[it->getVertex (2)].getPos () - vertices[it->getVertex (0)].getPos ());
        vec3Df n (vec3Df::crossProduct (e01, e02));
        n.normalize ();
        triangleNormals.push_back (n);
    }
}
void mesh::recomputeSmoothVertexNormals (unsigned int normWeight) {
    vector<vec3Df> triangleNormals;
    computeTriangleNormals (triangleNormals);
    for (std::vector<vertex>::iterator it = vertices.begin (); it != vertices.end (); it++)
        it->setNormal (vec3Df (0.0, 0.0, 0.0));
    vector<vec3Df>::const_iterator itNormal = triangleNormals.begin ();
    vector<triangle>::const_iterator it = triangles.begin ();
    for ( ; it != triangles.end (); it++, itNormal++) 
        for (unsigned int  j = 0; j < 3; j++) {
            vertex & vj = vertices[it->getVertex (j)];
            float w = 1.0; // uniform weights
            vec3Df e0 = vertices[it->getVertex ((j+1)%3)].getPos () - vj.getPos ();
            vec3Df e1 = vertices[it->getVertex ((j+2)%3)].getPos () - vj.getPos ();
            if (normWeight == 1) { // area weight
                w = vec3Df::crossProduct (e0, e1).getLength () / 2.0;
            } else if (normWeight == 2) { // angle weight
                e0.normalize ();
                e1.normalize ();
                w = (2.0 - (vec3Df::dotProduct (e0, e1) + 1.0)) / 2.0;
            } 
            if (w <= 0.0)
                continue;
            vj.setNormal (vj.getNormal () + (*itNormal) * w);
        }
    vertex::normalizeNormals (vertices);
}

void mesh::renderGL() const {
    glc->P();
    glBegin (GL_TRIANGLES);
    for (unsigned int i = 0; i < triangles.size (); i++) {
        const triangle & t = triangles[i];
        vertex v[3];
        float theta = 0;
        float phi = 0;

        // color per triangle
        for (unsigned int j = 0; j < 3; j++){
            v[j] = vertices[t.getVertex(j)];
            theta += v[j].getTheta();
            phi += v[j].getPhi();
        }
        theta = theta/3;
        phi = phi/3;

        bool sensor = true;
        for (unsigned int j = 0; j < 3; j++){
            if(prm->get_trianglescolor()) v[j].setcolor(theta,phi);                     //color per triangle
            else                          v[j].setcolor(v[j].getTheta(),v[j].getPhi()); //color per vertex

            glColor4f(v[j].getR(),v[j].getG(),v[j].getB(),v[j].getA());
            glNormal3f (v[j].getNormal()[0], v[j].getNormal()[1], v[j].getNormal()[2]);
            glVertex3f (v[j].getPos()[0],    v[j].getPos()[1],    v[j].getPos()[2]);

            sensor = sensor && v[j].getSensor();
        }
        if(sensor){                                                                     //sensor triangle, print both sides
            for (unsigned int j = 2; j > -1; j--){
                if(prm->get_trianglescolor()) v[j].setcolor(theta,phi);
                else                          v[j].setcolor(v[j].getTheta(),v[j].getPhi());

                glColor4f(v[j].getR(),v[j].getG(),v[j].getB(),v[j].getA());
                glNormal3f (v[j].getNormal()[0], v[j].getNormal()[1], v[j].getNormal()[2]);
                glVertex3f (v[j].getPos()[0],    v[j].getPos()[1],    v[j].getPos()[2]);
            }
        }
    }
    glEnd ();
    glc->Q();
}

void mesh::loadOFF (const std::string & filename){
    clear ();
    ifstream input (filename.c_str ());
    if (!input)
        throw Exception ("Failing opening the file.");
    string magic_word;
    input >> magic_word;
    if (magic_word != "OFF")
        throw Exception ("Not an OFF file.");
    unsigned int numOfVertices, numOfTriangles, numOfWhat;
    input >> numOfVertices >> numOfTriangles >> numOfWhat;
    for (unsigned int i = 0; i < numOfVertices; i++) {
        vec3Df pos;
        input >> pos;
        vertex v(pos);
        v.calcangles();
        vertices.push_back (v);
    }
    for (unsigned int i = 0; i < numOfTriangles; i++) {
        unsigned int polygonSize;
        input >> polygonSize;
        vector<unsigned int> index (polygonSize);
        for (unsigned int j = 0; j < polygonSize; j++)
            input >> index[j];
        for (unsigned int j = 1; j < (polygonSize - 1); j++)
            triangles.push_back (triangle (index[0], index[j], index[j+1]));
    }
    input.close ();
    recomputeSmoothVertexNormals (0);
}
