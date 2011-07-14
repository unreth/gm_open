#ifndef EEGCOORD_H
#define EEGCOORD_H

#include <QString>

#include "iostream"

using namespace std;

class eegcoord {
public:
    const static int ntheta = 9;
    const static float inittheta = 16.66;
    const static float steptheta = 18.75;   // angle total = (init-1)*step = 150
    const static int nphi = 9;
    const static float initphi = -5;
    const static float stepphi = 23.75;     // angle total = (init-1)*step = 190

    const static int iAF = 1;
    const static int iF =  2;
    const static int iFC = 3;
    const static int iT =  4;
    const static int iP =  6;
    const static int iO =  8;

    const static int j7 = 8;
    const static int j5 = 7;
    const static int j3 = 6;
    const static int j1 = 5;
    const static int j2 = 3;
    const static int j4 = 2;
    const static int j6 = 1;
    const static int j8 = 0;

    bool sensor[ntheta][nphi];
    QString labeli[ntheta];
    QString labelj[nphi];

    static eegcoord * getInstance();
    inline eegcoord(){
        //setting coords where there is any sensors
        for(int i=0; i<ntheta; i++){
            labeli[i] = QString();
            labelj[i] = QString();
            for(int j=0; j<nphi; j++){
                sensor[i][j]=false;
           }
        }
        sensor[eegcoord::iAF][eegcoord::j3] = true;        sensor[eegcoord::iAF][eegcoord::j4] = true;
        sensor[eegcoord::iF ][eegcoord::j7] = true;        sensor[eegcoord::iF ][eegcoord::j8] = true;
        sensor[eegcoord::iF ][eegcoord::j3] = true;        sensor[eegcoord::iF ][eegcoord::j4] = true;
        sensor[eegcoord::iFC][eegcoord::j5] = true;        sensor[eegcoord::iFC][eegcoord::j6] = true;
        sensor[eegcoord::iT ][eegcoord::j7] = true;        sensor[eegcoord::iT ][eegcoord::j8] = true;
        sensor[eegcoord::iP ][eegcoord::j7] = true;        sensor[eegcoord::iP ][eegcoord::j8] = true;
        sensor[eegcoord::iO ][eegcoord::j1] = true;        sensor[eegcoord::iO ][eegcoord::j2] = true;

        labeli[1] = QString("AF");
        labeli[2] = QString("F");
        labeli[3] = QString("FC");
        labeli[4] = QString("T");
        labeli[6] = QString("P");
        labeli[8] = QString("O");

        labelj[8] = QString("7");
        labelj[7] = QString("5");
        labelj[6] = QString("3");
        labelj[5] = QString("1");
        labelj[3] = QString("2");
        labelj[2] = QString("4");
        labelj[1] = QString("6");
        labelj[0] = QString("8");
    }
};

#endif // EEGCOORD_H
