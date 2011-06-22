#ifndef GLCOLOR_H
#define GLCOLOR_H

#include <QtXml/qdom.h>
#include <QGLViewer/qglviewer.h>
#include <iostream>
#include <cmath>

#include "vec3D.h"

using namespace std;

class eegcoord {
public:
    static const int ntheta = 9;
    static const float inittheta = 16.66;
    static const float steptheta = 18.75;   // angle total = (init-1)*step = 150
    static const int nphi = 9;
    static const float initphi = -5;
    static const float stepphi = 23.75;     // angle total = (init-1)*step = 190

    static const int iAF = 1;
    static const int iF =  2;
    static const int iFC = 3;
    static const int iT =  4;
    static const int iP =  6;
    static const int iO =  8;

    static const int j7 = 0;
    static const int j5 = 1;
    static const int j3 = 2;
    static const int j1 = 3;
    static const int j2 = 5;
    static const int j4 = 6;
    static const int j6 = 7;
    static const int j8 = 8;

    bool sensor[9][9];

    inline eegcoord(){
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                sensor[i][j]=false;
        sensor[iAF][j3] = true;        sensor[iAF][j4] = true;
        sensor[iF ][j7] = true;        sensor[iF ][j8] = true;
        sensor[iF ][j3] = true;        sensor[iF ][j4] = true;
        sensor[iFC][j5] = true;        sensor[iFC][j6] = true;
        sensor[iT ][j7] = true;        sensor[iT ][j8] = true;
        sensor[iP ][j7] = true;        sensor[iP ][j8] = true;
        sensor[iO ][j1] = true;        sensor[iO ][j2] = true;
    }
};

class glcolor {
public:
    float epsilon;
    bool points;
    bool lines;
    vec3Df bg;
    vec3Df eeg[eegcoord::ntheta][eegcoord::nphi];

    eegcoord eegc;

    //INITIALIZATION
    static glcolor * getInstance ();
    inline glcolor() {
        //draw
        epsilon = 0.2;
        points = true;
        lines = true;
        bg = vec3Df(1,1,1);
        int initcolor = 0;

        //eeg
        for(int i=0; i<eegcoord::ntheta; i++){    //theta
            for(int j=0; j<eegcoord::nphi; j++){  //phi
                switch(initcolor){
                case 0:
                    eeg[i][j] = vec3Df(0,0,0);                                                                                          //back
                    break;
                case 1:
                    eeg[i][j] = vec3Df(i/(float)(eegcoord::ntheta-1),i/(float)(eegcoord::ntheta-1),i/(float)(eegcoord::ntheta-1));      //theta
                    break;
                case 2:
                    eeg[i][j] = vec3Df(j/(float)(eegcoord::nphi-1),j/(float)(eegcoord::nphi-1),j/(float)(eegcoord::nphi-1));            //phi
                    break;
                case 3:
                    eeg[i][j] = vec3Df(i/(float)(eegcoord::ntheta-1),j/(float)(eegcoord::nphi-1),0);                                    //theta,phi
                    break;
                }
            }
        }
    }

    //SET
    inline void setEpsilon(float e) { this->epsilon = e; }
    inline void setPoints(bool p)   { this->points = p;  }
    inline void setLines(bool l)    { this->lines = l;   }
    inline void setBg(vec3Df b)     { this->bg = b;      }
    inline void setEeg(int i, int j, float eegsensor) {
        if(eegsensor > 1) eegsensor = 1;
        if(eegsensor < -1) eegsensor = -1;
        eeg[i][j][0] = 0.5*(1+eegsensor);
        eeg[i][j][1] = 0.5*(1+eegsensor);
        eeg[i][j][2] = 0;
    }

    //UPDATE
    inline void updateEeg() {
        //TODO!
        //interpolation of virtual sensors, for non-point modes
        for(int i=0; i<eegcoord::ntheta; i++){
            for(int j=0; j<eegcoord::nphi; j++){

            }
        }
    }

    //GET
    inline vec3Df getColor(float & theta, float & phi){
        eegc = eegcoord();

        float difftheta = theta - eegcoord::inittheta;  if(difftheta<0) difftheta+=360; if(difftheta>=360) difftheta=difftheta-360;
        float diffphi = phi   - eegcoord::initphi;      if(diffphi  <0) diffphi  +=360; if(diffphi  >=360) diffphi  =diffphi  -360;
        float i = (difftheta) /eegcoord::steptheta;
        float j = (diffphi)   /eegcoord::stepphi;
        int iround = round(i);
        int jround = round(j);

        if(!points || (eegc.sensor[iround][jround] && abs(i-iround)<epsilon && abs(j-jround)<epsilon)){     //points
        if(!lines  || (abs(i-iround)<epsilon || abs(j-jround)<epsilon)){                                    //lines
            if(i>=0 && i<eegcoord::ntheta-1 && j>=0 && j<eegcoord::nphi-1){                                 //working area
                vec3Df ret = eeg[iround][jround];
//                ret += (i-(int)i)*(eeg[(int)i+1][(int)j]-eeg[(int)i][(int)j]);
//                ret += (j-(int)j)*(eeg[(int)i][(int)j+1]-eeg[(int)i][(int)j]);
                return ret;
            } else return bg;
        } else return bg;
        } else return bg;
    }
};

#endif // GLCOLOR_H
