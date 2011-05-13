// *********************************************************
// Scene Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2010 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#include "Scene.h"
#include <string>
#include "Vec3D.h"
#include "Matrix.h"

using namespace std;

static Scene * instance = NULL;

void Scene::set_param(Parametres * param){
    this->param = param;
}

Scene * Scene::getInstance () {
    if (instance == NULL){
        instance = new Scene ();
    }
    return instance;
}
void Scene::destroyInstance () {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}
/**
* Constructeur de scène ici vous pouvez changer la scène à charger.
*/
Scene::Scene () {
    buildBrain();
    updateBoundingBox ();
}

Scene::~Scene () {
}

void Scene::updateBoundingBox () {
    if (objects.empty ())
        bbox = BoundingBox ();
    else {
        bbox = objects[0].getBoundingBox ();
        for (unsigned int i = 1; i < objects.size (); i++)
            bbox.extendTo (objects[i].getBoundingBox ());
    }
}
/**
*Méthode pour charger les fichiers sans devoir se souvenir du nom, on l'écrit une fois pour toute dans une enum ainsi c'est plus facile.
* @param objName est une enum qui peremet de trouver le nom de fichier sans devoir le taper à chaque fois.
*/
string getFileName(Object::objName objName){
    string out = "models/";
    switch(objName){
    case Object::ground:
        out+="ground.off";
        break;
    case Object::brain:
        out+="brain.off";
        break;
    case Object::newbrain:
        out+="newbrain.off";
        break;
    case Object::eeg:
        out+="eeg1020.off";
        break;
    }
    return out;
}


// Changer ce code pour créer des scènes originales

void Scene::buildBrain() {

    bool brain = true;
    bool sphere = false;
    bool axes = false;
    bool eegs = false;

    if(brain){
        //brain
        Mesh brain;
        string filebrain = getFileName(Object::brain);
        RotationMatrix brainrot(0, Matrix::Z);
        Vec3Df braintrans(0,0,0);
        float braingrand = 1.f;
        brain.loadOFF(filebrain,braintrans,braingrand,brainrot);
        Material brainmat(1.f,1.f, Vec3Df (1.f, 1.f, 1.f));
        Object brainobject(brain,brainmat);
        objects.push_back(brainobject);
    }

    if(sphere){
        //eeg
        Mesh eeg;
        string fileeeg = getFileName(Object::eeg);
        RotationMatrix eegrot(0, Matrix::Z);
        Vec3Df eegtrans(0,0,0);
        float eeggrand = 0.5f;
        eeg.loadOFF(fileeeg,eegtrans,eeggrand,eegrot);
        Material eegmat(1.f,1.f, Vec3Df (1.f, 1.f, 1.f));
        Object eegobject(eeg,eegmat);
        objects.push_back(eegobject);
    }

    if(axes){
        //sagital
        Mesh sagital1;
        string filesagital1 = getFileName(Object::ground);
        RotationMatrix sagital1rot(-90., Matrix::X);
        Vec3Df sagital1trans;
        float sagital1grand = 3.f;
        sagital1.loadOFF(filesagital1,sagital1trans,sagital1grand,sagital1rot);
        Material sagital1mat;
        Object sagital1object (sagital1, sagital1mat);
        objects.push_back(sagital1object);

        Mesh sagital2;
        string filesagital2 = getFileName(Object::ground);
        RotationMatrix sagital2rot(90., Matrix::X);
        Vec3Df sagital2trans;
        float sagital2grand = 3.f;
        sagital2.loadOFF(filesagital2,sagital2trans,sagital2grand,sagital2rot);
        Material sagital2mat;
        Object sagital2object (sagital2, sagital2mat);
        objects.push_back(sagital2object);

        //axial
        Mesh axial1;
        string fileaxial1 = getFileName(Object::ground);
        RotationMatrix axial1rot(0., Matrix::X);
        Vec3Df axial1trans(0,0,-0);
        float axial1grand = 3.f;
        axial1.loadOFF(fileaxial1,axial1trans,axial1grand,axial1rot);
        Material axial1mat;
        Object axial1object (axial1, axial1mat);
        objects.push_back(axial1object);

        Mesh axial2;
        string fileaxial2 = getFileName(Object::ground);
        RotationMatrix axial2rot(180., Matrix::X);
        Vec3Df axial2trans(0,0,-0);
        float axial2grand = 3.f;
        axial2.loadOFF(fileaxial2,axial2trans,axial2grand,axial2rot);
        Material axial2mat;
        Object axial2object (axial2, axial2mat);
        objects.push_back(axial2object);
    }

    if(eegs){

        //Y
        Mesh Y1;
        string fileY1 = getFileName(Object::ground);
        RotationMatrix Y1rot(36., Matrix::X);
        Vec3Df Y1trans;
        float Y1grand = 3.f;
        Y1.loadOFF(fileY1,Y1trans,Y1grand,Y1rot);
        Material Y1mat;
        Object Y1object (Y1, Y1mat);
        objects.push_back(Y1object);

        Mesh Y2;
        string fileY2 = getFileName(Object::ground);
        RotationMatrix Y2rot(72., Matrix::X);
        Vec3Df Y2trans;
        float Y2grand = 3.f;
        Y2.loadOFF(fileY2,Y2trans,Y2grand,Y2rot);
        Material Y2mat;
        Object Y2object (Y2, Y2mat);
        objects.push_back(Y2object);

        Mesh Y3;
        string fileY3 = getFileName(Object::ground);
        RotationMatrix Y3rot(108., Matrix::X);
        Vec3Df Y3trans;
        float Y3grand = 3.f;
        Y3.loadOFF(fileY3,Y3trans,Y3grand,Y3rot);
        Material Y3mat;
        Object Y3object (Y3, Y3mat);
        objects.push_back(Y3object);

        Mesh Y4;
        string fileY4 = getFileName(Object::ground);
        RotationMatrix Y4rot(144., Matrix::X);
        Vec3Df Y4trans;
        float Y4grand = 3.f;
        Y4.loadOFF(fileY4,Y4trans,Y4grand,Y4rot);
        Material Y4mat;
        Object Y4object (Y4, Y4mat);
        objects.push_back(Y4object);

        Mesh Y5;
        string fileY5 = getFileName(Object::ground);
        RotationMatrix Y5rot(180., Matrix::X);
        Vec3Df Y5trans;
        float Y5grand = 3.f;
        Y5.loadOFF(fileY5,Y5trans,Y5grand,Y5rot);
        Material Y5mat;
        Object Y5object (Y5, Y5mat);
        objects.push_back(Y5object);

        //Z
        Mesh Z1;
        string fileZ1 = getFileName(Object::ground);
        RotationMatrix Z1rot(18., Matrix::Z);
        Vec3Df Z1trans;
        float Z1grand = 3.f;
        Z1.loadOFF(fileZ1,Z1trans,Z1grand,Z1rot);
        Material Z1mat;
        Object Z1object (Z1, Z1mat);
        objects.push_back(Z1object);

        Mesh Z2;
        string fileZ2 = getFileName(Object::ground);
        RotationMatrix Z2rot(54., Matrix::Z);
        Vec3Df Z2trans;
        float Z2grand = 3.f;
        Z2.loadOFF(fileZ2,Z2trans,Z2grand,Z2rot);
        Material Z2mat;
        Object Z2object (Z2, Z2mat);
        objects.push_back(Z2object);

        Mesh Z3;
        string fileZ3 = getFileName(Object::ground);
        RotationMatrix Z3rot(90., Matrix::Z);
        Vec3Df Z3trans;
        float Z3grand = 3.f;
        Z3.loadOFF(fileZ3,Z3trans,Z3grand,Z3rot);
        Material Z3mat;
        Object Z3object (Z3, Z3mat);
        objects.push_back(Z3object);

        Mesh Z4;
        string fileZ4 = getFileName(Object::ground);
        RotationMatrix Z4rot(126., Matrix::Z);
        Vec3Df Z4trans;
        float Z4grand = 3.f;
        Z4.loadOFF(fileZ4,Z4trans,Z4grand,Z4rot);
        Material Z4mat;
        Object Z4object (Z4, Z4mat);
        objects.push_back(Z4object);

        Mesh Z5;
        string fileZ5 = getFileName(Object::ground);
        RotationMatrix Z5rot(162., Matrix::Z);
        Vec3Df Z5trans;
        float Z5grand = 3.f;
        Z5.loadOFF(fileZ5,Z5trans,Z5grand,Z5rot);
        Material Z5mat;
        Object Z5object (Z5, Z5mat);
        objects.push_back(Z5object);
    }
}

