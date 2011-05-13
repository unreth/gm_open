#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Vec3D.h"

#define PI 3.141592/180

using namespace std;

int main(int argc, char** argv){
    int theta[5];
    theta[0] = 18;
    theta[1] = 54;
    theta[2] = 90;
    theta[3] = 126;
    theta[4] = 162;

    int phi[6];
    phi[0] = -90;
    phi[1] = -54;
    phi[2] = -18;
    phi[3] = 18;
    phi[4] = 54;
    phi[5] = 90;

    ofstream output ("models/eeg1020.off");
    output << "OFF" << endl;

    output << 30 << " " << 40 << " " << 0 << endl;
    for (unsigned int i = 0; i < 5; i++) {
        for (unsigned int j = 0; j < 6; j++) {
            Vec3Df pos( cos(PI*theta[i]),
                        sin(PI*theta[i])*cos(PI*phi[j]),
                        sin(PI*theta[i])*sin(PI*phi[j]));
            output << pos << endl;
        }
    }
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 5; j++) {
            output << "3 " << i*6+j << " " << (i+1)*6+j << " " << (i+1)*6+j+1 << endl;
            output << "3 " << i*6+j << " " << (i+1)*6+j+1 << " " << i*6+j+1 << endl;
        }
    }
    output.close();
    return 0;
}

