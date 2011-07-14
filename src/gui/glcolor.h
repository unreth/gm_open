#ifndef GLCOLOR_H
#define GLCOLOR_H

#include <QtXml/qdom.h>
#include <QGLViewer/qglviewer.h>
#include <iostream>
#include <cmath>
#include <QSemaphore>

#include "eegcoord.h"
#include "vec3D.h"
#include "param.h"

using namespace std;

class glcolor : public QObject {
    Q_OBJECT
public:
    param * prm;

    vec3Df bg;
    vec3Df eeg[eegcoord::ntheta][eegcoord::nphi];
    QSemaphore * sem;   //epoc and glviewer concurrence

    eegcoord * eegc;      //map of sensors

    //INITIALIZATION
    static glcolor * getInstance ();
    inline glcolor() {
        sem = new QSemaphore(1);
        this->prm = param::getInstance();
        this->eegc = eegcoord::getInstance();

        for(int i=0; i<eegcoord::ntheta; i++)
            for(int j=0; j<eegcoord::nphi; j++)
                eeg[i][j] = prm->get_lines();
    }

    //semaphore methods
    inline void P() { sem->acquire(); }
    inline void Q() { sem->release(); }

    inline void set_prm(param * prm)      { this->prm = prm; }
    inline void set_eegc(eegcoord * eegc) { this->eegc = eegc; }
    inline eegcoord * get_eegc()          { return eegc; }

    //reset color map
    inline void setAllEeg(){
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                eeg[i][j] = prm->get_lines();
    }
    inline void setEeg(int i, int j, vec3Df c) {
        eeg[i][j] = c;
    }
    inline void setEeg(int i, int j, float eegsensor) {
        // -1: blue
        //  0: green
        // +1: red
        if(eegsensor > 1) eegsensor = 1;
        if(eegsensor < -1) eegsensor = -1;

        if(eegsensor > 0 ) {
            eeg[i][j][0] = eegsensor;
            eeg[i][j][1] = (1-eegsensor);
            eeg[i][j][2] = 0;
        } else {
            eeg[i][j][0] = 0;
            eeg[i][j][1] = (1+eegsensor);
            eeg[i][j][2] = -eegsensor;
        }
    }
    inline vec3Df getColor(float & theta, float & phi, float & alfa,  bool & sensor){
        //estimates position from theta and phi
        //defines alfa(transparency) and if the vertex is in a sensor zone
        //interpolates color
        //estimates i,j

        float difftheta = theta - eegcoord::inittheta;  if(difftheta<0) difftheta+=360; if(difftheta>=360) difftheta=difftheta-360;
        float diffphi = phi   - eegcoord::initphi;      if(diffphi  <0) diffphi  +=360; if(diffphi  >=360) diffphi  =diffphi  -360;
        float i = (difftheta) / eegcoord::steptheta;
        float j = (diffphi)   / eegcoord::stepphi;
        int iround = round(i);
        int jround = round(j);

        if(prm->get_draw()>0 || (eegc->sensor[iround][jround] && abs(i-iround)<prm->get_epsilon() && abs(j-jround)<prm->get_epsilon())){      //points
        if(prm->get_draw()>1 || (abs(i-iround)<prm->get_epsilon() || abs(j-jround)<prm->get_epsilon())){                                      //lines
            if(i>=0 && i<eegcoord::ntheta-1 && j>=0 && j<eegcoord::nphi-1){                                                                   //working area
                //sensor zone. setting alfa and sensor
                if(eegc->sensor[iround][jround]) alfa = 1;
                else                             alfa = prm->get_alfa();

                sensor = true;

                vec3Df ret;
                if(prm->get_grad()){
                    //gradient
                    int inext,jnext;
                    float pi, pj;

                    if(i>iround)    inext = iround+1;
                    else            inext = iround-1;
                    if(j>jround)    jnext = jround+1;
                    else            jnext = jround-1;

                    pi = fabs(i-iround);
                    pj = fabs(j-jround);
                    ret = pi*pj*eeg[inext][jnext] + pi*(1-pj)*eeg[inext][jround] + (1-pi)*pj*eeg[iround][jnext] + (1-pi)*(1-pj)*eeg[iround][jround];
                } else {
                    //no gradient
                    ret = eeg[iround][jround];
                }
                return ret;
            //not a sensor zone.
            } else { alfa=prm->get_alfa(); sensor=false; return prm->get_brain(); }
        } else { alfa=prm->get_alfa(); sensor=false; return prm->get_brain(); }
        } else { alfa=prm->get_alfa(); sensor=false; return prm->get_brain(); }
    }
};

#endif // GLCOLOR_H
