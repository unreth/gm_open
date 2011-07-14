// *********************************************************
// vertex Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2008 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#include "vertex.h"

using namespace std;

static const unsigned int SIZE_OF_VERTEX = 10;

ostream & operator<< (ostream & output, const vertex & v) {
    output << v.getPos () << endl << v.getNormal ();
    return output;
}

void vertex::normalizeNormals (vector<vertex> & vertices) {
    for (std::vector<vertex>::iterator it = vertices.begin (); 
         it != vertices.end (); 
         it++) {
        vec3Df n = it->getNormal ();
        if (n != vec3Df (0.0, 0.0, 0.0)) {
            n.normalize ();
            it->setNormal (n);
        }
    }    
}
