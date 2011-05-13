// ---------------------------------------------------------
// mesh Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2008 Tamy Boubekeur.
// All rights reserved.
// ---------------------------------------------------------

#include "mesh.h"

using namespace std;

static mesh * instance = NULL;

mesh * mesh::getInstance () {
    if (instance == NULL){
        instance = new mesh ();
    }
    return instance;
}

void mesh::clear () {
    clearTopology ();
    clearGeometry ();
}

void mesh::clearGeometry () {
    vertices.clear ();
}

void mesh::clearTopology () {
    triangles.clear ();
}

void mesh::unmarkAllVertices () {
    for (unsigned int i = 0; i < vertices.size (); i++)
        vertices[i].unmark ();
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

void mesh::collectOneRing (vector<vector<unsigned int> > & oneRing) const {
    oneRing.resize (vertices.size ());
    for (unsigned int i = 0; i < triangles.size (); i++) {
        const triangle & ti = triangles[i];
        for (unsigned int j = 0; j < 3; j++) {
            unsigned int vj = ti.getVertex (j);
            for (unsigned int k = 1; k < 3; k++) {
                unsigned int vk = ti.getVertex ((j+k)%3);
                if (find (oneRing[vj].begin (), oneRing[vj].end (), vk) == oneRing[vj].end ())
                    oneRing[vj].push_back (vk);
            }
        }
    }
}

void mesh::collectOrderedOneRing (vector<vector<unsigned int> > & oneRing) const {
    oneRing.resize (vertices.size ());
    for (unsigned int t = 0; t < triangles.size (); t++) {
        const triangle & ti = triangles[t];
        for (unsigned int i = 0; i < 3; i++) {
            unsigned int vi = ti.getVertex (i);
            unsigned int vj = ti.getVertex ((i+1)%3);
            unsigned int vk = ti.getVertex ((i+2)%3);
            vector<unsigned int> & oneRingVi = oneRing[vi];
            vector<unsigned int>::iterator begin = oneRingVi.begin ();
            vector<unsigned int>::iterator end = oneRingVi.end ();
            vector<unsigned int>::iterator nj = find (begin, end, vj);
            vector<unsigned int>::iterator nk = find (begin, end, vk);
            if (nj != end && nk == end) {
                if (nj == begin)
                    nj = end;
                nj--;
                oneRingVi.insert (nj, vk);
            } else if (nj == end && nk != end) 
                oneRingVi.insert (nk, vj);
            else if (nj == end && nk == end) {
                oneRingVi.push_back (vk);
                oneRingVi.push_back (vj);
            }
        }
    }
}

void mesh::computeDualEdgeMap (edgeMapIndex & dualVMap1, edgeMapIndex & dualVMap2) {
    for (vector<triangle>::iterator it = triangles.begin ();
         it != triangles.end (); it++) {
        for (unsigned int i = 0; i < 3; i++) {
            edge eij (it->getVertex (i), it->getVertex ((i+1)%3)); 
            if (dualVMap1.find (eij) == dualVMap1.end ())
                dualVMap1[eij] = it->getVertex ((i+2)%3);
            else
                dualVMap2[eij] = it->getVertex ((i+2)%3);
        }
    } 
}

void mesh::markBorderEdges (edgeMapIndex & edgeMap) {
    for (vector<triangle>::iterator it = triangles.begin ();
         it != triangles.end (); it++) {
        for (unsigned int i = 0; i < 3; i++) {
            unsigned int j = (i+1)%3;
            edge eij (it->getVertex (i), it->getVertex (j)); 
            if (edgeMap.find (eij) == edgeMap.end ())
                edgeMap[eij] = 0;
            else 
                edgeMap[eij] += 1;
        }
    } 
}

void mesh::renderGL() const {
    glBegin (GL_TRIANGLES);
    for (unsigned int i = 0; i < triangles.size (); i++) {
        const triangle & t = triangles[i];
        vertex v[3];
        for (unsigned int j = 0; j < 3; j++)
            v[j] = vertices[t.getVertex(j)];
        for (unsigned int j = 0; j < 3; j++){
            v[j].calcangles();
            v[j].setcolor();
            glColor3f(v[j].getR(),v[j].getG(),v[j].getB());
            glNormal3f (v[j].getNormal()[0], v[j].getNormal()[1], v[j].getNormal()[2]);
            glVertex3f (v[j].getPos()[0],    v[j].getPos()[1],    v[j].getPos()[2]);
        }
    }
    glEnd ();
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
        vertices.push_back (vertex (pos, vec3Df (1.0, 0.0, 0.0)));
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
