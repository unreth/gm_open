#ifndef GLCOLOR_H
#define GLCOLOR_H

#include <QGLViewer/qglviewer.h>
#include <iostream>
#include <cmath>

#include "vec3D.h"

using namespace std;

class glcolor
{
public:
    vec3Df color[5][6];
    static const int ntheta = 5;
    static const int nphi = 6;

    static glcolor * getInstance ();

    inline glcolor() {
        //theta
        for(int i=0; i<ntheta; i++){
            //phi
            for(int j=0; j<nphi; j++){
                color[i][j] = vec3Df(i/(float)(ntheta-1),i/(float)(ntheta-1),i/(float)(ntheta-1)); //theta
//                color[i][j] = vec3Df(j/(float)(nphi-1),j/(float)(nphi-1),j/(float)(nphi-1)); //phi
//                color[i][j] = vec3Df(1,1,1);                            //blanc
            }
        }
    }
    inline void set(int i, int j, GLfloat r,GLfloat g,GLfloat b) {
        color[i][j][0] = r;
        color[i][j][1] = g;
        color[i][j][2] = b;
    }
    inline vec3Df getColor(float & theta, float & phi){
        // valeurs spheriques
//        float i = (ntheta-1)*theta/180.;
//        float j = (nphi-1)*phi/360.;


        float steptheta = 33.33;
        float inittheta = steptheta/2;
        float i = (theta-inittheta)/steptheta;
        if(i<0) i=0.5;
        if(i>ntheta) i=ntheta-1.5;

        float initphi = 0;
        float stepphi = 36;
        float j = (phi-initphi)/stepphi;
        if(j<0) j=0.5;
        if(j>nphi) j=nphi-1.5;

        float epsilon = 0.3;
        if(abs(i-(int)i)<epsilon && abs(j-(int)j)<epsilon){
            vec3Df ret = color[(int)i][(int)j];
//            ret += (i-(int)i)*(color[(int)i+1][(int)j]-color[(int)i][(int)j]);
//            ret += (j-(int)j)*(color[(int)i][(int)j+1]-color[(int)i][(int)j]);
            return ret;
        } else return vec3Df(0.5,0,0);
    }
};

#endif // GLCOLOR_H
