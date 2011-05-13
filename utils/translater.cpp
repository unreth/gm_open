#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Vec3D.h"

using namespace std;

int main(int argc, char** argv){
    ifstream input ("models/brain.off");
    ofstream output ("newbrain.off");
    string magic_word;
    input >> magic_word;
    output << magic_word << endl;
    unsigned int numOfVertices, numOfTriangles, numOfWhat;
    input >> numOfVertices >> numOfTriangles >> numOfWhat;
    output << numOfVertices << " " << numOfTriangles << " " << numOfWhat << endl;
    for (unsigned int i = 0; i < numOfVertices; i++) {
        Vec3Df pos;
        input >> pos;
        pos += -Vec3Df(0,1,0);
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
