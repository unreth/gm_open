#ifndef EPOC_H
#define EPOC_H

#include <iostream>
#include <QThread>

#include "driver/libepoc.h"

using namespace std;

class epoc : public QThread
{
public:
    static epoc * getInstance ();
    inline epoc() { read = false; }
    void run();

private:
    bool read;
};

#endif // EPOC_H
