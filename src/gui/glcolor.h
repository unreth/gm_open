#ifndef GLCOLOR_H
#define GLCOLOR_H

#include <QGLViewer/qglviewer.h>
#include <iostream>
#include <cmath>

#include "vec3D.h"

using namespace std;

class eegcoord {
    //emotiv epoc: AF3, F7, F3, FC5, T7, P7, O1, O2, P8, T8, FC6, F4, F8, AF4.

    static const int FP1i= 0;
    static const int FP2i= 0;
    static const int F7i = 1;
    static const int F3i = 1;
    static const int Fzi = 1;
    static const int F4i = 1;
    static const int F8i = 1;
    static const int T3i = 2;
    static const int C3i = 2;
    static const int Czi = 2;
    static const int C4i = 2;
    static const int T4i = 2;
    static const int T5i = 3;
    static const int P3i = 3;
    static const int Pzi = 3;
    static const int P4i = 3;
    static const int T6i = 3;
    static const int O1i = 4;
    static const int O2i = 4;

    static const int FP1j= 0;
    static const int FP2j= 4;
    static const int F7j = 0;
    static const int F3j = 1;
    static const int Fzj = 2;
    static const int F4j = 3;
    static const int F8j = 4;
    static const int T3j = 0;
    static const int C3j = 1;
    static const int Czj = 2;
    static const int C4j = 3;
    static const int T4j = 4;
    static const int T5j = 0;
    static const int P3j = 1;
    static const int Pzj = 2;
    static const int P4j = 3;
    static const int T6j = 4;
    static const int O1j = 0;
    static const int O2j = 4;

};

class glcolor
{
public:
    static const int ntheta = 5;
    static const float steptheta = 33.33;
    static const float inittheta = 16.66;
    static const int nphi = 6;
    static const float initphi = 0;
    static const float stepphi = 34;

    float epsilon;
    bool points;
    bool lines;
    vec3Df bg;
    vec3Df eeg[5][6];

    static glcolor * getInstance ();

    inline glcolor() {
        epsilon = 0.1;
        points = false;
        lines = false;
        bg = vec3Df(1,1,1);

        for(int i=0; i<ntheta; i++){    //theta
            for(int j=0; j<nphi; j++){  //phi
//                eeg[i][j] = vec3Df(1,1,1);                                                          //blanc
                eeg[i][j] = vec3Df(i/(float)(ntheta-1),i/(float)(ntheta-1),i/(float)(ntheta-1));    //theta
                eeg[i][j] = vec3Df(j/(float)(nphi-1),j/(float)(nphi-1),j/(float)(nphi-1));          //phi
//                eeg[i][j] = vec3Df(i/(float)(ntheta-1),j/(float)(nphi-1),0);                        //theta,phi
            }
        }
    }
    inline void setEpsilon(float e) { this->epsilon = e; }
    inline void setPoints(bool p)   { this->points = p;  }
    inline void setLines(bool l)    { this->lines = l;   }
    inline void setBg(vec3Df b)     { this->bg = b;      }
    inline void setEeg(int i, int j, GLfloat r,GLfloat g,GLfloat b) {
        eeg[i][j][0] = r;
        eeg[i][j][1] = g;
        eeg[i][j][2] = b;
    }
    inline vec3Df getColor(float & theta, float & phi){
        float i = (theta-inittheta)/steptheta;
        float j = (phi-initphi)/stepphi;

        if(!points || (abs(i-(int)i)<epsilon && abs(j-(int)j)<epsilon)){    //points
        if(!lines  || (abs(i-(int)i)<epsilon || abs(j-(int)j)<epsilon)){    //lines
            if(i>=0 && i<ntheta-1 && j>=0 && j<nphi-1){                     //working area
                vec3Df ret = eeg[(int)i][(int)j];
                ret += (i-(int)i)*(eeg[(int)i+1][(int)j]-eeg[(int)i][(int)j]);
                ret += (j-(int)j)*(eeg[(int)i][(int)j+1]-eeg[(int)i][(int)j]);
                return ret;
            } else return bg;
        } else return bg;
        } else return bg;
    }
};

#endif // GLCOLOR_H
