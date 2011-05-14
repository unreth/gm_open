#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "../src/gui/vec3D.h"

#define PI 3.141592

using namespace std;

class matrix{
public:
    //attributes
    double m[4][4];
    double teta;
    //constructor
    inline matrix(double l0v0,double l0v1, double l0v2, double l0v3,
                  double l1v0,double l1v1, double l1v2, double l1v3,
                  double l2v0,double l2v1, double l2v2, double l2v3,
                  double l3v0,double l3v1, double l3v2, double l3v3,
                  double teta){
        this->m[0][0] = l0v0;
        this->m[0][1] = l0v1;
        this->m[0][2] = l0v2;
        this->m[0][3] = l0v3;

        this->m[1][0] = l1v0;
        this->m[1][1] = l1v1;
        this->m[1][2] = l1v2;
        this->m[1][3] = l1v3;

        this->m[2][0] = l2v0;
        this->m[2][1] = l2v1;
        this->m[2][2] = l2v2;
        this->m[2][3] = l2v3;

        this->m[3][0] = l3v0;
        this->m[3][1] = l3v1;
        this->m[3][2] = l3v2;
        this->m[3][3] = l3v3;

        this->teta = teta;
    }
    inline matrix(double _teta, vec3Df axis){
        axis.normalize();
        float c = cos(_teta*PI/180.);
        float s = sin(_teta*PI/180.);
        float ux = axis[0];
        float uy = axis[1];
        float uz = axis[2];
        new (this) matrix ( ux*ux +(1.-ux*ux)*c,        ux*uy*(1-c) - uz*s ,    ux*uz*(1-c) + uy*s ,    0.,
                                   ux*uy*(1-c) + uz*s,  uy*uy +(1.-uy*uy)*c,    uy*uz*(1-c) - ux*s ,    0. ,
                                   ux*uz*(1-c) - uy*s,  uy*uz*(1-c) + ux*s ,    uz*uz +(1.-uz*uz)*c  ,  0.,
                                   0.,                  0.,                     0.,                     0.,
                                   _teta);
    }

    //methods
    inline vec3Df operator*( vec3Df &vec){
        vec3Df v;
        v[0] = this->m[0][0]*vec[0]+m[0][1]*vec[1]+m[0][2]*vec[2];//+m[0][3];
        v[1] = this->m[1][0]*vec[0]+m[1][1]*vec[1]+m[1][2]*vec[2];//+m[1][3];
        v[2] = this->m[2][0]*vec[0]+m[2][1]*vec[1]+m[2][2]*vec[2];//+m[2][3];
        return v;
    }
};

int main(int argc, char** argv){
    ifstream input ("../models/brain.off");
    ofstream output ("../models/newbrain.off");
    string magic_word;
    input >> magic_word;
    output << magic_word << endl;
    unsigned int numOfVertices, numOfTriangles, numOfWhat;
    input >> numOfVertices >> numOfTriangles >> numOfWhat;
    output << numOfVertices << " " << numOfTriangles << " " << numOfWhat << endl;

    for (unsigned int i = 0; i < numOfVertices; i++) {
        vec3Df pos;
        input >> pos;

        matrix r(-5,vec3Df(0,0,1));
        pos = r*pos;
        output << pos << endl;
    }
    for (unsigned int i = 0; i < numOfTriangles; i++) {
        unsigned int polygonSize;
        input >> polygonSize;
        output << polygonSize << " ";
        vector<unsigned int> index (polygonSize);
        for (unsigned int j = 0; j < polygonSize; j++){
            input >> index[j];
            output << index[j] << " ";
        }
        output << endl;
    }
    input.close ();
    output.close ();
    output.close();
    return 0;
}
