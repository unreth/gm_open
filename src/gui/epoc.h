#ifndef EPOC_H
#define EPOC_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QThread>

#include "glcolor.h"
#include "driver/libepoc.h"

using namespace std;

class epoc : public QThread
{
public:
    static epoc * getInstance ();
    inline epoc() { read = true; }

    void run();

private:
    bool read;
};

#endif // EPOC_H
