#ifndef GLCOLOR_H
#define GLCOLOR_H

#include <QGLViewer/qglviewer.h>
#include <iostream>

#include "vec3D.h"

using namespace std;

class glcolor
{
public:
    vec3Df color[5][6];

    static glcolor * getInstance ();

    inline glcolor() {
        for(int i=0; i<5; i++){
            for(int j=0; j<6; j++){
                color[i][j] = vec3Df(random()/(float)RAND_MAX,random()/(float)RAND_MAX,random()/(float)RAND_MAX);
                cout << color[i][j] << endl;
            }
        }
    }
    inline void set(int i, int j, GLfloat r,GLfloat g,GLfloat b) {
        color[i][j][0] = r;
        color[i][j][1] = g;
        color[i][j][2] = b;
    }
    inline vec3Df & getColor(float & theta, float & phi){
        int i = (int)((theta-18)/36);
        int j = (int)(phi/36);
        return color[i][j];
    }
};

#endif // GLCOLOR_H
