#ifndef EPOC_H
#define EPOC_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <vector>

#include <QEvent>
#include <QKeyEvent>

#include <QMainWindow>
#include <QThread>
#include <QGLViewer/quaternion.h>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <ctime>
#include <time.h>
#include <QToolButton>
#include <QLabel>
#include <QSlider>

#include "eegcoord.h"
#include "glcolor.h"
#include "src/driver/libepoc.h"
#include "glviewer.h"

using namespace std;

class glviewer;

class epoc : public QThread
{
    Q_OBJECT
public:

    //constructors
    inline epoc() {
        init();
    }
    inline epoc(epoc * e){
        init();
    }
    inline void init(){
        phi = 0;
        vx = 0; vy = 0;
        saveFile = "rec";
        openFile = "rec";
        pause = false;
        time_sliderPress = false;
        moving = false;
        sem = new QSemaphore(1);
    }
    inline void connect_signals(){
        QObject * p = parent();
        connect (this, SIGNAL(stop()), p, SLOT(file_stop()));
    }

    inline virtual ~epoc() {}

    void run();

signals:
    void stop();

    //methods
public slots:

    // INSTANCES & SET -----------------------------------------------------------------------------------------------------------------------------------------
    inline void setglv(glviewer * glv)                      { this->glv = glv; }
    inline void setprm(param * prm)                         { this->prm = prm; setpvid(prm->get_pvid()); setkey(prm->get_key()); }
    inline void set_vx(int vx)                              { this->vx = vx; }
    inline void set_vy(int vy)                              { this->vy = vy; }

    // EPOC PARAMETERS------------------------------------------------------------------------------------------------------------------------------------------
    inline void setpvid(int pvid) {
        prm->set_pvid(pvid);
    }
    inline void setkey(int key) {
        prm->set_key(key);
    }

    // GUI  -----------------------------------------------------------------------------------------------------------------------------------------------------
    inline void set_pauseButton(QToolButton * pauseButton)  { this->pauseButton = pauseButton; }
    inline void set_timenow(QLabel * time_nowLabel)         { this->time_nowLabel = time_nowLabel; }
    inline void set_timenow(float time_now) {
        //acquire the semaphore first!
        int s = time_now;
        int m = s/60;
        s = s - m*60;

        QString dString = QString::number(time_now-(int)time_now);
        if(dString.length() <= 2) dString = "00";
        else if(dString.length() == 3) dString = dString.at(2)+QString("0");
        else if(dString.length() >= 4) dString = dString.at(2)+QString(dString.at(3));
        QString sString = QString::number(s);
        if(sString.length()==1) sString = "0"+sString;
        QString mString = QString::number(m);
        if(mString.length()==1) mString = "0"+mString;

        time_nowLabel->setText(mString+":"+sString+"."+dString);
    }

    inline void set_timeslider(QSlider * time_slider)       { this->timeSlider = time_slider; }
    inline void set_timemax(QLabel * time_maxLabel)         { this->time_maxLabel = time_maxLabel; }

    // MODES -----------------------------------------------------------------------------------------------------------------------------------------------------
    inline void set_mode(int mode)                          { this->mode = mode; }
    inline void set_save() {
        saveFile = QFileDialog::getSaveFileName(0,tr("Save"),saveFile,"");
        if(saveFile!=0) {
            mode = 1;
        }
    }
    inline void set_open() {
        QFileDialog openDialog;
        openFile = openDialog.getOpenFileName(0,tr("Open"),openFile,"");
        if(openFile!=0) {
            mode = 2;
        }

        //creating lines_pos list (position of the beginning of each line, needed for set_movingSlider)
        QFile * ffd;
        ffd = new QFile(openFile);
        ffd->open(QIODevice::ReadOnly | QIODevice::Text);

        ffd->readLine();        //total time
        lines_pos.clear();
        while(!ffd->atEnd()){
            lines_pos.push_back(ffd->pos());
            ffd->readLine();
        }
        ffd->close();
    }

    inline void save_frame(){
        // please take the semaphore!
        time_now = clock(); ts << (time_now-time_start) << "\t"; //sync
        ts << frame.AF3 << "\t";
        ts << frame.AF4 << "\t";
        ts << frame.F7  << "\t";
        ts << frame.F8  << "\t";
        ts << frame.F3  << "\t";
        ts << frame.F4  << "\t";
        ts << frame.FC5 << "\t";
        ts << frame.FC6 << "\t";
        ts << frame.T7  << "\t";
        ts << frame.T8  << "\t";
        ts << frame.P7  << "\t";
        ts << frame.P8  << "\t";
        ts << frame.O1  << "\t";
        ts << frame.O2  << endl;
    }
    inline void read_frame(){
        // please take the semaphore!
        QString n;
        ts >> n; frame.AF3 = n.toInt();
        ts >> n; frame.AF4 = n.toInt();
        ts >> n; frame.F7  = n.toInt();
        ts >> n; frame.F8  = n.toInt();
        ts >> n; frame.F3  = n.toInt();
        ts >> n; frame.F4  = n.toInt();
        ts >> n; frame.FC5 = n.toInt();
        ts >> n; frame.FC6 = n.toInt();
        ts >> n; frame.T7  = n.toInt();
        ts >> n; frame.T8  = n.toInt();
        ts >> n; frame.P7  = n.toInt();
        ts >> n; frame.P8  = n.toInt();
        ts >> n; frame.O1  = n.toInt();
        ts >> n; frame.O2  = n.toInt();
        toread = true;
    }
    inline void print_frame(){
        // please take the semaphore!
        glcolor * glc = glcolor::getInstance();
        eegcoord * egc = eegcoord::getInstance();

        struct epoc_frame tmp = frame;

        glc->P();
        if(egc->sensor[eegcoord::iAF][eegcoord::j3])
            glc->setEeg(eegcoord::iAF,  eegcoord::j3,(tmp.AF3-prm->get_c(eegcoord::iAF,  eegcoord::j3)) /(float)prm->get_r(eegcoord::iAF,  eegcoord::j3));
        if(egc->sensor[eegcoord::iAF][eegcoord::j4])
            glc->setEeg(eegcoord::iAF,  eegcoord::j4,(tmp.AF4-prm->get_c(eegcoord::iAF,  eegcoord::j4)) /(float)prm->get_r(eegcoord::iAF,  eegcoord::j4));
        if(egc->sensor[eegcoord::iF][eegcoord::j7])
            glc->setEeg(eegcoord::iF,   eegcoord::j7,(tmp.F7 -prm->get_c(eegcoord::iF,   eegcoord::j7)) /(float)prm->get_r(eegcoord::iF,   eegcoord::j7));
        if(egc->sensor[eegcoord::iF][eegcoord::j8])
            glc->setEeg(eegcoord::iF,   eegcoord::j8,(tmp.F8 -prm->get_c(eegcoord::iF,   eegcoord::j8)) /(float)prm->get_r(eegcoord::iF,   eegcoord::j8));
        if(egc->sensor[eegcoord::iF][eegcoord::j3])
            glc->setEeg(eegcoord::iF,   eegcoord::j3,(tmp.F3 -prm->get_c(eegcoord::iF,   eegcoord::j3)) /(float)prm->get_r(eegcoord::iF,   eegcoord::j3));
        if(egc->sensor[eegcoord::iF][eegcoord::j4])
            glc->setEeg(eegcoord::iF,   eegcoord::j4,(tmp.F4 -prm->get_c(eegcoord::iF,   eegcoord::j4)) /(float)prm->get_r(eegcoord::iF,   eegcoord::j4));
        if(egc->sensor[eegcoord::iFC][eegcoord::j5])
            glc->setEeg(eegcoord::iFC,  eegcoord::j5,(tmp.FC5-prm->get_c(eegcoord::iFC,  eegcoord::j5)) /(float)prm->get_r(eegcoord::iFC,  eegcoord::j5));
        if(egc->sensor[eegcoord::iFC][eegcoord::j6])
            glc->setEeg(eegcoord::iFC,  eegcoord::j6,(tmp.FC6-prm->get_c(eegcoord::iFC,  eegcoord::j6)) /(float)prm->get_r(eegcoord::iFC,  eegcoord::j6));
        if(egc->sensor[eegcoord::iT][eegcoord::j7])
            glc->setEeg(eegcoord::iT,   eegcoord::j7,(tmp.T7 -prm->get_c(eegcoord::iT,   eegcoord::j7)) /(float)prm->get_r(eegcoord::iT,   eegcoord::j7));
        if(egc->sensor[eegcoord::iT][eegcoord::j8])
            glc->setEeg(eegcoord::iT,   eegcoord::j8,(tmp.T8 -prm->get_c(eegcoord::iT,   eegcoord::j8)) /(float)prm->get_r(eegcoord::iT,   eegcoord::j8));
        if(egc->sensor[eegcoord::iP][eegcoord::j7])
            glc->setEeg(eegcoord::iP,   eegcoord::j7,(tmp.P7 -prm->get_c(eegcoord::iP,   eegcoord::j7)) /(float)prm->get_r(eegcoord::iP,   eegcoord::j7));
        if(egc->sensor[eegcoord::iP][eegcoord::j8])
            glc->setEeg(eegcoord::iP,   eegcoord::j8,(tmp.P8 -prm->get_c(eegcoord::iP,   eegcoord::j8)) /(float)prm->get_r(eegcoord::iP,   eegcoord::j8));
        if(egc->sensor[eegcoord::iO][eegcoord::j1])
            glc->setEeg(eegcoord::iO,   eegcoord::j1,(tmp.O1 -prm->get_c(eegcoord::iO,   eegcoord::j1)) /(float)prm->get_r(eegcoord::iO,   eegcoord::j1));
        if(egc->sensor[eegcoord::iO][eegcoord::j2])
            glc->setEeg(eegcoord::iO,   eegcoord::j2,(tmp.O2 -prm->get_c(eegcoord::iO,   eegcoord::j2)) /(float)prm->get_r(eegcoord::iO,   eegcoord::j2));
        glc->Q();
        toread = false;
    }

    // TIME ------------------------------------------------------------------------------------------------------------------------------------------------------
    inline bool get_pause()                                 { return pause; }
    inline void set_pause(bool pause) {
        this->pause = pause;
        if(pause)       pauseButton->setIcon(QIcon("icons/play.png"));
        else            pauseButton->setIcon(QIcon("icons/pause.png"));
    }
    inline void set_sliderPress() {
        time_sliderPress = true;
        //pause. if not when playing the signal could be called!
        old_pause = pause;
        pause = true;
    }
    inline void set_sliderRelease() {
        time_sliderPress = false;
        pause = old_pause;
    }
    inline void set_sliderMoving(int value) {
        if(time_sliderPress && !moving && (clock()-time_flushSlide)>prm->get_timeflush()){
            moving = true;  //do that first! if not, thread will be blocked
            sem->acquire();

            QString  n;

            ts >> n;
            sliderValue = n.toInt()/(prm->get_timeres()*1000000);

            //GOING FORWARD (to the right)
            while(sliderValue < value){
                ts.seek(lines_pos[currentline++]);
                ts >> n;
                sliderValue = n.toInt()/(prm->get_timeres()*1000000);
            }

            //GOING BACKWARD (to the left)
            if(value < sliderValue){
                while(value < sliderValue){
                    ts.seek(lines_pos[--currentline]);
                    ts >> n;
//                    if(n.toInt()>0)
                        sliderValue = n.toInt()/(prm->get_timeres()*1000000);
                }
                currentline++;  //for the read_frame!
            }

            read_frame(); print_frame();                            //print the frame in the brain
            set_timenow(value*prm->get_timeres());                  //set the timenow label
            time_start = clock()-value*prm->get_timeres()*1000000;  //set the clock values
            time_flushSlide = clock();                              //set the flush time, so ti won't load colors too early
            sem->release();
            moving = false;
        }
    }

    int numepocs();
    int launch();

private:
    int mode;               //0=realtime, 1=save, 2=open

    //mode==open variables..
    int currentline;        //current line while reading the file..
    vector<int> lines_pos;  //position on each line
    bool moving;            //set_sliderMoving called
    int sliderValue;        //value on the slider (allows to remember the last value befor calling set_sliderMoving)
    bool time_sliderPress;  //needed. if not, set_sliderMoving is called while playing
    bool pause, old_pause;

    bool toread;            //if there is something to read on the frame


    float phi;              //y angle of the brain
    float vx, vy;           //speed on x, y

    QSemaphore * sem;

    QString saveFile, openFile;
    clock_t time_start, time_now, time_total;
    QToolButton * pauseButton;
    QLabel * time_nowLabel, * time_maxLabel;
    QSlider * timeSlider;
    clock_t time_flushSlide;

    QFile * fd;
    QTextStream ts;

    glviewer * glv;
    param * prm;

    epoc_device * d;
    struct epoc_frame frame;
};

#endif // EPOC_H
