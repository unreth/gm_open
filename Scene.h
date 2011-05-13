// *********************************************************
// Scene Class
// Author : Tamy Boubekeur (boubek@gmail.com).
// Copyright (C) 2010 Tamy Boubekeur.
// All rights reserved.
// *********************************************************

#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>

class Scene {
public:
    void set_param(Parametres * param);

    static Scene * getInstance ();
    static void destroyInstance ();
    

protected:
    Scene ();
    virtual ~Scene ();
    
private:
    void buildBrain();
};


#endif // SCENE_H

