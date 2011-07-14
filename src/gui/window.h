#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QScrollArea>
#include <QGroupBox>
#include <QLayout>
#include <QAction>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QCheckBox>
#include <QSlider>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QColorDialog>

#include "eegcoord.h"
#include "glviewer.h"
#include "mesh.h"
#include "param.h"
#include "checkbox.h"
#include "slider.h"
#include "spinbox.h"

class window : public QMainWindow {
    Q_OBJECT
public:
    static window * getInstance ();
    window();
    virtual ~window();
    
private :
    param    * prm;
    epoc     * epocthread;

    // viewer
    glviewer * viewer;

    // control
    QScrollArea * controlScroll;
    QWidget     * controlWidget;
    QGroupBox   * renderLabel ,     * epocLabel,         * sensorsLabel,    * fileLabel;
    QGroupBox   * renderGroupBox ,  * epocGroupBox,      * sensorsGroupBox, * fileGroupBox;
    //render
    QComboBox   * render_meshComboBox;
    QComboBox   * render_drawComboBox;
    QLabel      * render_alfaLabel;
    QSlider     * render_alfaSlider;
    QLabel      * render_epsilonLabel;
    QSlider     * render_epsilonSlider;
    QCheckBox   * render_lightingCheckBox;
    QCheckBox   * render_trianglescolorCheckBox;
    QCheckBox   * render_gradCheckBox;
    // epoc
    QComboBox   * epoc_keyComboBox, * epoc_pvidComboBox, * epoc_numComboBox;
    QPushButton * epoc_startedButton;
    QCheckBox   * epoc_xCheckBox,   * epoc_yCheckBox,    * epoc_accelerarionCheckBox;
    // file
    QWidget     * timerGroupBox;
    QLabel      * file_timenowLabel,* file_timemaxLabel;
    QSlider     * file_timeSlider;
    QPushButton * file_saveButton,  * file_openButton,   * file_stopButton;
    QToolButton * file_pauseButton;
    // sensor
    QAction     * sliderAction;
    QPushButton * sensors_allButton;
    QSpinBox    * sensors_xspeedSpinBox, * sensors_yspeedSpinBox;
    checkbox    * sensors_CheckBox[eegcoord::nphi][eegcoord::ntheta];
    spinbox     * sensors_cSpinBox[eegcoord::nphi][eegcoord::ntheta], *sensors_rSpinBox[eegcoord::nphi][eegcoord::ntheta];
    slider      * sensors_cSlider[eegcoord::nphi][eegcoord::ntheta],  *sensors_rSlider[eegcoord::nphi][eegcoord::ntheta];

public slots:

    // DOCK
    // -----------------------------------------------

    inline void set_rendergb()  { renderLabel->setVisible(renderGroupBox->isVisible());    renderGroupBox->setVisible (!renderGroupBox->isVisible());       adjust(); }
    inline void set_epocgb()    { epocLabel->setVisible(epocGroupBox->isVisible());        epocGroupBox->setVisible   (!epocGroupBox->isVisible());         adjust(); }
    inline void set_filegb()    { fileLabel->setVisible(fileGroupBox->isVisible());        fileGroupBox->setVisible   (!fileGroupBox->isVisible());         adjust(); }
    inline void set_sensorsgb() { sensorsLabel->setVisible(sensorsGroupBox->isVisible());    sensorsGroupBox->setVisible (!sensorsGroupBox->isVisible());   adjust(); }

    inline void adjust() {
        renderGroupBox->adjustSize();
        epocGroupBox->adjustSize();
        fileGroupBox->adjustSize();
        sensorsGroupBox->adjustSize();
        controlWidget->adjustSize();
    }


    // RENDER SETTINGS
    // -----------------------------------------------

    inline void set_mesh (int m) {
        prm->set_mesh(m); mesh::getInstance()->loadmesh();
    }
    inline void set_draw (int d) {
        prm->set_draw(d);
        render_epsilonLabel->setVisible(d!=2);
        render_epsilonSlider->setVisible(d!=2);
    }

    inline void set_brain () {
        QColor c = QColorDialog::getColor (QColor ((int)(255*prm->get_brain()[0]), (int)(255*prm->get_brain()[1]), (int)(255*prm->get_brain()[2])), this);
        if (c.isValid () == true) { vec3Df vc(c.red()/255.,c.green()/255.,c.blue()/255.); prm->set_brain(vc); }
    }
    inline void set_lines () {
        QColor c = QColorDialog::getColor (QColor ((int)(255*prm->get_lines()[0]), (int)(255*prm->get_lines()[1]), (int)(255*prm->get_lines()[2])), this);
        if (c.isValid () == true) { vec3Df vc(c.red()/255.,c.green()/255.,c.blue()/255.); prm->set_lines(vc); glcolor::getInstance()->setAllEeg(); }
    }
    inline void set_bg () {
        QColor c = QColorDialog::getColor (QColor ((int)(255*prm->get_bg()[0]), (int)(255*prm->get_bg()[1]), (int)(255*prm->get_bg()[2])), this);
        if (c.isValid () == true) { vec3Df vc(c.red()/255.,c.green()/255.,c.blue()/255.); prm->set_bg(vc); viewer->setBackgroundColor(c); }
    }

    // EPOC SETTINGS
    // -----------------------------------------------
    inline void epoc_new() {
        epocthread = new epoc(epocthread);
        epocthread->setParent(this);
        epocthread->connect_signals();
        epocthread->set_pauseButton(file_pauseButton);
        epocthread->set_timenow(file_timenowLabel);
        epocthread->set_timeslider(file_timeSlider);
        epocthread->set_timemax(file_timemaxLabel);
        epocthread->setglv(viewer);
        epocthread->setprm(prm);
    }

    inline void set_x(bool x){ epocthread->set_vx(0); prm->set_x(x); }
    inline void set_y(bool y){ epocthread->set_vy(0); prm->set_y(y); }
    inline void set_acceleration(bool a){
        if(a){
            epocthread->set_vx(0);      epocthread->set_vy(0);
            prm->set_xspeed(100000);    prm->set_yspeed(100000);
        } else {
            prm->set_xspeed(500);    prm->set_yspeed(500);
        }
        sensors_xspeedSpinBox->setValue(prm->get_xspeed());
        sensors_yspeedSpinBox->setValue(prm->get_yspeed());
        prm->set_acceleration(a);
    }

    inline void set_key(int key)   { epocthread->setkey(key);   update_numepocs(); }
    inline void set_pvid(int pvid) { epocthread->setpvid(pvid); update_numepocs(); }
    inline void update_numepocs () {
        int numepocs = epocthread->numepocs();
        epoc_numComboBox->clear();
        for(int i=0; i<numepocs; i++){
            epoc_numComboBox->addItem(QString::number(i));
        }
        if(epocthread->numepocs()==0)   epoc_startedButton->setEnabled(false);
        else                            epoc_startedButton->setEnabled(true);
    }

    inline void set_numepoc (int numepoc) {
        if(numepoc < epocthread->numepocs())
            prm->set_numepoc(numepoc);
        else
            epoc_numComboBox->setCurrentIndex(prm->get_numepoc());
    }
    inline void set_started () {
        if(prm->get_started()){
            //we disconnect
            epocthread->set_pause(false);
            prm->set_started(false);
            epoc_startedButton->setText("Start");
            epoc_keyComboBox->setEnabled(true);
            epoc_pvidComboBox->setEnabled(true);
            epoc_numComboBox->setEnabled(true);
        } else {
            //we connect
            prm->set_started(true);
            epoc_new();
            epocthread->set_mode(0);
            if(epocthread->launch()){
                //connection done
                epoc_startedButton->setText("Stop");
                epoc_keyComboBox->setDisabled(true);
                epoc_pvidComboBox->setDisabled(true);
                epoc_numComboBox->setDisabled(true);
                file_stopButton->setDisabled(true);
            } else  prm->set_started(false);
        }
    }

    // FILE SETTINGS
    // -----------------------------------------------
    inline void file_save(){
        prm->set_started(true);
        epoc_new();
        epocthread->set_save();
        if(epocthread->launch()) {

            file_saveButton->setVisible(false);
            file_openButton->setVisible(false);
            file_stopButton->setVisible(true);
            file_stopButton->setText("Stop");

            epoc_keyComboBox->setDisabled(true);
            epoc_pvidComboBox->setDisabled(true);
            epoc_numComboBox->setDisabled(true);
            epoc_startedButton->setDisabled(true);

            adjust();
        }
        else  prm->set_started(false);
    }
    inline void file_open(){
        prm->set_started(true);
        epoc_new();
        epocthread->set_open();
        epocthread->set_pause(true);
        epocthread->launch();

        file_saveButton->setVisible(false);
        file_stopButton->setVisible(true);
        file_stopButton->setText("Back");
        timerGroupBox->setVisible(true);

        epoc_keyComboBox->setDisabled(true);
        epoc_pvidComboBox->setDisabled(true);
        epoc_numComboBox->setDisabled(true);
        epoc_startedButton->setDisabled(true);

        adjust();
    }
    inline void set_pause() {
        epocthread->set_pause(!epocthread->get_pause());
    }
    inline void set_sliderPress()   { epocthread->set_sliderPress(); }
    inline void set_sliderRelease() { epocthread->set_sliderRelease(); }
    inline void set_sliderMoving(int v)  { epocthread->set_sliderMoving(v); }
    inline void file_stop(){
        //we disconnect
        epoc_keyComboBox->setEnabled(true);
        epoc_pvidComboBox->setEnabled(true);
        epoc_numComboBox->setEnabled(true);
        epoc_startedButton->setEnabled(true);

        file_saveButton->setVisible(true);
        file_openButton->setVisible(true);
        file_stopButton->setVisible(false);
        timerGroupBox->setVisible(false);

        prm->set_started(false);

        adjust();
    }


    // SENSOR SETTINGS
    // -----------------------------------------------

    inline void set_all(){
        bool all = !prm->get_all();
        prm->set_all(all);

        if(all) {
            sensors_allButton->setText("Uncheck all");
        } else {
            sensors_allButton->setText("Check all");
        }

        set_sensorCheckBox(eegcoord::iAF,eegcoord::j3,all);
        set_sensorCheckBox(eegcoord::iAF,eegcoord::j4,all);
        set_sensorCheckBox(eegcoord::iF, eegcoord::j7,all);
        set_sensorCheckBox(eegcoord::iF, eegcoord::j8,all);
        set_sensorCheckBox(eegcoord::iF, eegcoord::j3,all);
        set_sensorCheckBox(eegcoord::iF, eegcoord::j4,all);
        set_sensorCheckBox(eegcoord::iFC,eegcoord::j5,all);
        set_sensorCheckBox(eegcoord::iFC,eegcoord::j6,all);
        set_sensorCheckBox(eegcoord::iT, eegcoord::j7,all);
        set_sensorCheckBox(eegcoord::iT, eegcoord::j8,all);
        set_sensorCheckBox(eegcoord::iP, eegcoord::j7,all);
        set_sensorCheckBox(eegcoord::iP, eegcoord::j8,all);
        set_sensorCheckBox(eegcoord::iO, eegcoord::j1,all);
        set_sensorCheckBox(eegcoord::iO, eegcoord::j2,all);

        sensors_CheckBox[eegcoord::iAF][eegcoord::j3]->setChecked(all);
        sensors_CheckBox[eegcoord::iAF][eegcoord::j4]->setChecked(all);
        sensors_CheckBox[eegcoord::iF ][eegcoord::j7]->setChecked(all);
        sensors_CheckBox[eegcoord::iF ][eegcoord::j8]->setChecked(all);
        sensors_CheckBox[eegcoord::iF ][eegcoord::j3]->setChecked(all);
        sensors_CheckBox[eegcoord::iF ][eegcoord::j4]->setChecked(all);
        sensors_CheckBox[eegcoord::iFC][eegcoord::j5]->setChecked(all);
        sensors_CheckBox[eegcoord::iFC][eegcoord::j6]->setChecked(all);
        sensors_CheckBox[eegcoord::iT ][eegcoord::j7]->setChecked(all);
        sensors_CheckBox[eegcoord::iT ][eegcoord::j8]->setChecked(all);
        sensors_CheckBox[eegcoord::iP ][eegcoord::j7]->setChecked(all);
        sensors_CheckBox[eegcoord::iP ][eegcoord::j8]->setChecked(all);
        sensors_CheckBox[eegcoord::iO ][eegcoord::j1]->setChecked(all);
        sensors_CheckBox[eegcoord::iO ][eegcoord::j2]->setChecked(all);
    }
    inline void set_sensorCheckBox(bool s){
        checkbox * c = (checkbox *) sender();
        int i = c->get_i();
        int j = c->get_j();
        set_sensorCheckBox(i,j,s);
    }
    inline void set_sensorCheckBox(int i, int j, bool s){
        eegcoord::getInstance()->sensor[i][j] = s;
        if(s){
            sensors_cSlider[i][j]->setVisible(s);
            sensors_cSpinBox[i][j]->setVisible(!s);
            sensors_rSlider[i][j]->setVisible(s);
            sensors_rSpinBox[i][j]->setVisible(!s);
        } else {
            glcolor::getInstance()->setEeg(i,j,prm->get_lines());
            sensors_cSlider[i][j]->setVisible(false);
            sensors_cSpinBox[i][j]->setVisible(false);
            sensors_rSlider[i][j]->setVisible(false);
            sensors_rSpinBox[i][j]->setVisible(false);
        }
        controlWidget->adjustSize();
    }
    inline void set_slider(){
        eegcoord * egc = eegcoord::getInstance();
        bool s = !prm->get_slider();
        prm->set_slider(s);
        for(int i=0; i<eegcoord::nphi; i++){
            for(int j=0; j<eegcoord::ntheta; j++){
                if(egc->sensor[i][j]){
                    sensors_cSlider[i][j]->setVisible(s);
                    sensors_cSpinBox[i][j]->setVisible(!s);
                    sensors_rSlider[i][j]->setVisible(s);
                    sensors_rSpinBox[i][j]->setVisible(!s);
                }
            }
        }
        adjust();
    }
    inline void set_cSlider(int c) {
        slider * s = (slider *)sender();
        int i = s->get_i();
        int j = s->get_j();
        prm->set_c(i,j,c);
        sensors_cSpinBox[i][j]->setValue(c);
    }
    inline void set_cSpinBox(int c) {
        spinbox * s = (spinbox *)sender();
        int i = s->get_i();
        int j = s->get_j();
        prm->set_c(i,j,c);
        sensors_cSlider[i][j]->setValue(c);
    }
    inline void set_rSlider(int r) {
        slider * s = (slider *)sender();
        int i = s->get_i();
        int j = s->get_j();
        prm->set_r(i,j,r);
        sensors_rSpinBox[i][j]->setValue(r);
    }
    inline void set_rSpinBox(int r) {
        spinbox * s = (spinbox *)sender();
        int i = s->get_i();
        int j = s->get_j();
        prm->set_r(i,j,r);
        sensors_rSlider[i][j]->setValue(r);
    }

    // APP
    // -----------------------------------------------

    inline void reset() {
        epocthread->set_pause(false);

        prm->reset();

        viewer->camera()->setPosition(qglviewer::Vec(0,0,12.4));
        viewer->camera()->setOrientation(0,0);
        viewer->reinit();

        //render
        render_meshComboBox->setCurrentIndex        (prm->get_mesh());
        render_alfaSlider->setValue                 (prm->get_alfa());
        render_drawComboBox->setCurrentIndex        (prm->get_draw());
        render_epsilonSlider->setValue              (prm->get_epsilon());
        render_lightingCheckBox->setChecked         (prm->get_lighting());
        render_trianglescolorCheckBox->setChecked   (prm->get_trianglescolor());
        render_gradCheckBox->setChecked             (prm->get_grad());
        // epoc
        epoc_keyComboBox->setCurrentIndex           (prm->get_key());   epoc_keyComboBox->setEnabled(true);
        epoc_pvidComboBox->setCurrentIndex          (prm->get_pvid());  epoc_pvidComboBox->setEnabled(true);
        update_numepocs();
        set_numepoc(prm->get_numepoc());
        epoc_startedButton->setText                 ("Start");
        epoc_xCheckBox->setChecked                  (prm->get_x());
        epoc_yCheckBox->setChecked                  (prm->get_y());
        epoc_accelerarionCheckBox->setChecked       (prm->get_acceleration());
        // file
        file_saveButton->setVisible(true);
        file_openButton->setVisible(true);
        file_stopButton->setVisible(false);
        timerGroupBox->setVisible(false);
        // sensor
        sensors_xspeedSpinBox->setValue             (prm->get_xspeed());
        sensors_yspeedSpinBox->setValue             (prm->get_yspeed());
        prm->set_all(false); set_all();
        for(int i=0; i<eegcoord::nphi; i++){
            for(int j=0; j<eegcoord::ntheta; j++){
                if(eegcoord::getInstance()->sensor[i][j]){
                    sensors_cSpinBox[i][j]->setValue(prm->get_c(i,j));  sensors_cSpinBox[i][j]->setVisible(!prm->get_slider());
                    sensors_rSpinBox[i][j]->setValue(prm->get_r(i,j));  sensors_rSpinBox[i][j]->setVisible(!prm->get_slider());
                    sensors_cSlider[i][j]->setValue(prm->get_c(i,j));   sensors_cSlider[i][j]->setVisible(prm->get_slider());
                    sensors_rSlider[i][j]->setValue(prm->get_r(i,j));   sensors_rSlider[i][j]->setVisible(prm->get_slider());
                }
            }
        }
    }
};

#endif // WINDOW_H
