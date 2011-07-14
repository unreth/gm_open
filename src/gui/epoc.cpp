#include "epoc.h"

using namespace qglviewer;

void reset(struct epoc_frame & frame){
    param * prm = param::getInstance();
    frame.F3 = prm->get_c(eegcoord::iF,eegcoord::j3);
    frame.FC6= prm->get_c(eegcoord::iFC,eegcoord::j6);
    frame.P7 = prm->get_c(eegcoord::iP,eegcoord::j7);
    frame.T8 = prm->get_c(eegcoord::iT,eegcoord::j8);
    frame.F7 = prm->get_c(eegcoord::iF,eegcoord::j7);
    frame.F8 = prm->get_c(eegcoord::iF,eegcoord::j8);
    frame.T7 = prm->get_c(eegcoord::iT,eegcoord::j7);
    frame.P8 = prm->get_c(eegcoord::iP,eegcoord::j8);
    frame.F4 = prm->get_c(eegcoord::iF,eegcoord::j4);
    frame.AF3= prm->get_c(eegcoord::iAF,eegcoord::j3);
    frame.AF4= prm->get_c(eegcoord::iAF,eegcoord::j4);
    frame.O2 = prm->get_c(eegcoord::iO,eegcoord::j2);
    frame.O1 = prm->get_c(eegcoord::iO,eegcoord::j1);
    frame.FC5= prm->get_c(eegcoord::iFC,eegcoord::j5);
}

void epoc::run(){
    glcolor * glc = glcolor::getInstance();
    eegcoord * egc = eegcoord::getInstance();

    char data[32];


    // INIT ---------------------------------------------------------------------------------------------------------------------
    sem->acquire();
    //opening file
    if(mode==1) {
        fd = new QFile(saveFile);
        fd->open(QIODevice::WriteOnly);
        ts.setDevice(fd);

        ts << "                    " << endl;   //as long as the max unsigned long long int (20 chars)
    } else if(mode==2) {

        fd = new QFile(openFile);
        fd->open(QIODevice::ReadOnly | QIODevice::Text);
        ts.setDevice(fd);

        //read the file itself
        ts >> time_total;

        float d = time_total/1000000.;
        int s = d;
        timeSlider->setMaximum(d/prm->get_timeres());
        int m = s/60;
        s = s - m*60;

        QString dString = QString::number(d-(int)d);
        if(dString.length() <= 2) dString = "00";
        else if(dString.length() == 3) dString = dString.at(2)+QString("0");
        else if(dString.length() >= 4) dString = dString.at(2)+QString(dString.at(3));
        QString sString = QString::number(s);
        if(sString.length()==1) sString = "0"+sString;
        QString mString = QString::number(m);
        if(mString.length()==1) mString = "0"+mString;

        time_nowLabel->setText("00:00.00");
        timeSlider->setValue(0);
        time_flushSlide = clock();
        sliderValue = 0;
        time_maxLabel->setText(mString+":"+sString+"."+dString);

        currentline = 0;
    }
    sem->release();

    // LOOP ---------------------------------------------------------------------------------------------------------------------
    time_start = clock();
    time_now = clock();
    while(prm->get_started()
          && (time_now-time_start)<time_total) {    //not really needed..

        //eeg data update
        if(mode==2) {
            //load mode

            //pause
            if(pause){
                while(pause);
                sem->acquire();
                time_start = clock()-timeSlider->value()*prm->get_timeres()*1000000;
                sem->release();
            }

            //read
            QString n;
            ts >> n; do { time_now=clock(); } while(time_now-time_start < n.toInt());   //sync
            sem->acquire();
            float timenow_sec = (time_now-time_start)/1000000.;
            set_timenow(timenow_sec);
            //set time
            timeSlider->setValue((int)(timenow_sec/(float)prm->get_timeres()));
            if(n.toInt()<0){
                sem->release();
                break;
            }
            read_frame();
            currentline++;
            sem->release();
        } else {
            //real-time mode

            toread = epoc_read_data(d, (uint8_t*)data) > 0 ;
            if(toread)  epoc_get_next_frame(&frame, (unsigned char*)data);

        }

        if(toread) {
            sem->acquire();
            print_frame();
            if(mode==1){
                //save mode
                save_frame();
            }
            sem->release();
        }


        //gyroscope update
        if(mode!=2 && prm->get_x()){
            if(prm->get_acceleration()){
                vx += frame.gyroX/(float)prm->get_xspeed();
            } else {
                vx = frame.gyroX/(float)prm->get_xspeed();
            }
            Quaternion quatx(Vec(0,cos(phi),sin(phi)),vx);
            glv->camera()->setPosition(quatx.rotate(glv->camera()->position()));
            quatx *= glv->camera()->orientation();
            glv->camera()->setOrientation(quatx);
        }
        if(mode!=2 && prm->get_y()){
            if(prm->get_acceleration()){
                vy += -frame.gyroY/(float)prm->get_yspeed();
            } else {
                vy = -frame.gyroY/(float)prm->get_yspeed();
            }

            phi += vy;
            if(phi > .5*PI){
                phi += -vy;
                vy = 0;
            } else if (phi < -.5*PI) {
                phi += -vy;
                vy = 0;
            }

            Quaternion quaty(Vec(1,0,0),vy);
            glv->camera()->setPosition(quaty.rotate(glv->camera()->position()));
            quaty *= glv->camera()->orientation();
            glv->camera()->setOrientation(quaty);
        }
    }

    //closing driver instance
    epoc_close(d);
    epoc_delete(d);

    //closing file
    if(mode==1) {
        ts << "-1" << endl;
        ts.seek(0);
        ts << (time_now-time_start) << endl;
    }
    if(mode!=0) fd->close();

    //turning glcolor to normal state
    glc->setAllEeg();

    //turning gui to normal state
    if(mode==2) emit stop();

}

int epoc::numepocs(){
    //number of emotiv epoc connected
    int numepocs;

    d = epoc_create();

    switch(prm->get_key()){
    case 0: epoc_init(CONSUMER_HEADSET); break;
    case 1: epoc_init(RESEARCH_HEADSET); break;
    case 2: epoc_init(SPECIAL_HEADSET);  break;
    }

    switch(prm->get_pvid()){
    case 0: numepocs = epoc_get_count(d, EPOC_VID, EPOC_PID); break;
    case 1: numepocs = epoc_get_count(d, NEW_VID,  NEW_PID); break;
    }

    epoc_close(d);
    epoc_delete(d);

    return numepocs;
}

int epoc::launch(){
    //launches the thread
    d = epoc_create();

    switch(prm->get_key()){
    case 0: epoc_init(CONSUMER_HEADSET); break;
    case 1: epoc_init(RESEARCH_HEADSET); break;
    case 2: epoc_init(SPECIAL_HEADSET);  break;
    }

    uint32_t pid, vid;
    switch(prm->get_pvid()){
    case 0: vid=EPOC_VID; pid=EPOC_PID; break;
    case 1: vid=NEW_VID;  pid=NEW_PID;  break;
    }

    if(mode!=2 && epoc_open(d, vid, pid, 0) != 0)       // TO REVIEW
    {
        epoc_close(d);
        epoc_delete(d);
        return 0;
    }
    this->start();
    return 1;
}
