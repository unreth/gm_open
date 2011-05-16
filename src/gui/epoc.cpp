#include "epoc.h"
#include "glcolor.h"
#include "mesh.h"

#include <stdio.h>
#include <stdlib.h>

static epoc * instance = NULL;

epoc * epoc::getInstance () {
    if (instance == NULL){
        instance = new epoc();
    }
    return instance;
}


void reset(struct epoc_frame & frame){
    frame.F3 = 0;
    frame.FC6= 0;
    frame.P7 = 0;
    frame.T8 = 0;
    frame.F7 = 0;
    frame.F8 = 0;
    frame.T7 = 0;
    frame.P8 = 0;
    frame.F4 = 0;
    frame.AF3= 0;
    frame.O2 = 0;
    frame.O1 = 0;
    frame.FC5= 0;
}


void epoc::run(){
    enum headset_type type;
    struct epoc_frame frame;

    epoc_device* d;
    char data[32];

    type = RESEARCH_HEADSET;

    epoc_init(type);

    d = epoc_create();
    cout << "Current epoc devices connected: " << epoc_get_count(d, EPOC_VID, EPOC_PID) << endl;
    if(epoc_open(d, EPOC_VID, EPOC_PID, 0) != 0)
    {
        cout <<  "CANNOT CONNECT" << endl;
        return;
    }
    read = true;
    glcolor * glc = glcolor::getInstance();
    mesh * glm = mesh::getInstance();
    int i=0;
    while(1)
    {
        while(!read);
        if(epoc_read_data(d, (uint8_t*)data) > 0 )
        {
            epoc_get_next_frame(&frame, (unsigned char*)data);
            glc->setEeg(eegcoord::iF,   eegcoord::j3,(frame.F3 -8540)/800.);
            glc->setEeg(eegcoord::iFC,  eegcoord::j6,(frame.FC6-8250)/800.);
            glc->setEeg(eegcoord::iP,   eegcoord::j7,(frame.P7 -8380)/800.);
            glc->setEeg(eegcoord::iT,   eegcoord::j8,(frame.T8 -7700)/800.);
            glc->setEeg(eegcoord::iF,   eegcoord::j7,(frame.F7 -8315)/800.);
            glc->setEeg(eegcoord::iF,   eegcoord::j8,(frame.F8 -8350)/800.);
            glc->setEeg(eegcoord::iT,   eegcoord::j7,(frame.T7 -8980)/800.);
//            glc->setEeg(eegcoord::iP,   eegcoord::j8,(frame.P8 - ?)/800.);
            glc->setEeg(eegcoord::iF,   eegcoord::j4,(frame.F4 -8620)/800.);
            glc->setEeg(eegcoord::iAF,  eegcoord::j3,(frame.AF3-8265)/800.);
            glc->setEeg(eegcoord::iO,   eegcoord::j2,(frame.O2 -8950)/800.);
            glc->setEeg(eegcoord::iO,   eegcoord::j1,(frame.O1 -8075)/800.);
            glc->setEeg(eegcoord::iFC,  eegcoord::j5,(frame.FC5-8700)/800.);
//            glm->renderGL();
        }
    }

    epoc_close(d);
    epoc_delete(d);
    return;
}
