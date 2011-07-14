#include "window.h"

using namespace std;

static window * windowinstance = NULL;

window * window::getInstance () {
    if (windowinstance == NULL){
        windowinstance = new window();
    }
    return windowinstance;
}

window::window () : QMainWindow (NULL) {


    // INSTANCES
    // ----------------------------------------------

    try                           { viewer = new glviewer(); }
    catch (glviewer::Exception e) {  cerr << e.getMessage () << endl; exit (1); }

    prm = param::getInstance();
    epocthread = new epoc();
    epocthread->setParent(this);
    epocthread->setglv(viewer);
    epocthread->setprm(prm);

    // ACTIONS
    // ----------------------------------------------

    QAction * renderAction    = new QAction(this);
    QAction * epocAction      = new QAction(this);
    QAction * fileAction      = new QAction(this);
    QAction * sensorsAction   = new QAction(this);
    sliderAction              = new QAction(this);
    QAction * resetAction      = new QAction(this);
    QAction * quitAction      = new QAction(this);

    connect ( renderAction ,  SIGNAL(triggered()) , this , SLOT(set_rendergb()) );
    connect ( epocAction  ,   SIGNAL(triggered()) , this , SLOT(set_epocgb()) );
    connect ( fileAction ,    SIGNAL(triggered()) , this , SLOT(set_filegb()) );
    connect ( sensorsAction , SIGNAL(triggered()) , this , SLOT(set_sensorsgb()) );
    connect ( sliderAction ,  SIGNAL(triggered()) , this , SLOT(set_slider()));
    connect ( resetAction   ,  SIGNAL(triggered()) , this , SLOT(reset()));
    connect ( quitAction   ,  SIGNAL(triggered()) , qApp , SLOT(closeAllWindows()) );

    renderAction->setShortcut(tr("r"));
    epocAction->setShortcut(tr("e"));
    fileAction->setShortcut(tr("f"));
    sensorsAction->setShortcut(tr("s"));
    sliderAction->setShortcut(tr("x"));
    resetAction->setShortcut(tr("Ctrl+r"));
    quitAction->setShortcut(tr("Ctrl+q"));

    addAction(renderAction);
    addAction(epocAction);
    addAction(fileAction);
    addAction(sensorsAction);
    addAction(sliderAction);
    addAction(resetAction);
    addAction(quitAction);

    // *********************************************************************************************************************************//
    // *                                                            GUI                                                                *//
    // *********************************************************************************************************************************//

    QWidget * mainGroupBox = new QWidget(this);
    mainGroupBox->setStyleSheet("background-color: white;");
    QHBoxLayout * mainLayout = new QHBoxLayout (mainGroupBox);


    // VIEWER
    // ----------------------------------------------

    QGroupBox * viewerGroupBox = new QGroupBox();
    QVBoxLayout * viewerLayout = new QVBoxLayout();
    viewerGroupBox->setLayout(viewerLayout);

        // viewer (glviewer)
        viewer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        viewerLayout->addWidget(viewer);

        // TIMER
        timerGroupBox = new QWidget();
        timerGroupBox->setVisible(false);
        QHBoxLayout * timerLayout = new QHBoxLayout();
        timerGroupBox->setLayout(timerLayout);

            // pause (pushbutton)
            file_pauseButton  = new QToolButton();
            connect (file_pauseButton, SIGNAL(clicked()) , this, SLOT (set_pause()));
            epocthread->set_pauseButton(file_pauseButton);
            timerLayout->addWidget (file_pauseButton);

            // time_now (label)
            file_timenowLabel = new QLabel("");
            epocthread->set_timenow(file_timenowLabel);
            timerLayout->addWidget(file_timenowLabel);

            // time_slider (slider)
            file_timeSlider = new QSlider(Qt::Horizontal,this);
            connect(file_timeSlider,SIGNAL(sliderPressed()),this,SLOT(set_sliderPress()));
            connect(file_timeSlider,SIGNAL(sliderReleased()),this,SLOT(set_sliderRelease()));
            connect(file_timeSlider,SIGNAL(valueChanged(int)),this,SLOT(set_sliderMoving(int)));
            epocthread->set_timeslider(file_timeSlider);
            timerLayout->addWidget(file_timeSlider);

            // time_max (label)
            file_timemaxLabel = new QLabel("");
            epocthread->set_timemax(file_timemaxLabel);
            timerLayout->addWidget(file_timemaxLabel);

        viewerLayout->addWidget(timerGroupBox);

    mainLayout->addWidget(viewerGroupBox);


    // CONTROL
    // ----------------------------------------------

    controlScroll = new QScrollArea();
    controlScroll->setFrameStyle(0);
    controlWidget = new QWidget ();
    controlWidget->setFixedWidth(225);
    QVBoxLayout * controlLayout = new QVBoxLayout(controlWidget);


         // RENDER GROUP_BOX
        // ----------------------------------------------

        renderLabel = new QGroupBox("Render Settings", controlWidget);
        renderLabel->setFixedWidth(prm->get_controlwidth());
        controlLayout->addWidget(renderLabel);

        renderGroupBox = new QGroupBox ("Render Settings", controlWidget);
        renderGroupBox->setFixedWidth(prm->get_controlwidth());
        QVBoxLayout * renderLayout = new QVBoxLayout (renderGroupBox);


            // mesh (combobox)
            render_meshComboBox = new QComboBox();
            render_meshComboBox->addItem("minimal");
            render_meshComboBox->addItem("low resolution");
            render_meshComboBox->addItem("high resolution");
            render_meshComboBox->setCurrentIndex(prm->get_mesh());
            connect(render_meshComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(set_mesh(int)));
            renderLayout->addWidget(render_meshComboBox);

            // alfa (slider)
            render_alfaLabel = new QLabel("Alpha");
            renderLayout->addWidget(render_alfaLabel);
            render_alfaSlider = new QSlider(Qt::Horizontal);
            render_alfaSlider->setMaximum(100);
            render_alfaSlider->setValue((int)prm->get_alfa()*100);
            connect(render_alfaSlider,SIGNAL(sliderMoved(int)),prm,SLOT(set_alfa(int)));
            renderLayout->addWidget(render_alfaSlider);

            // draw (combobox)
            render_drawComboBox = new QComboBox();
            render_drawComboBox->addItem("Points");
            render_drawComboBox->addItem("Lines");
            render_drawComboBox->addItem("Surface");
            render_drawComboBox->setCurrentIndex(prm->get_draw());
            connect(render_drawComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(set_draw(int)));
            renderLayout->addWidget(render_drawComboBox);

            // epsilon (slider)
            render_epsilonLabel = new QLabel("Point Width");
            render_epsilonLabel->setVisible(prm->get_draw()!=2);
            renderLayout->addWidget(render_epsilonLabel);
            render_epsilonSlider = new QSlider(Qt::Horizontal);
            render_epsilonSlider->setMaximum(500);
            render_epsilonSlider->setValue((int)(prm->get_epsilon()*1000));
            render_epsilonSlider->setVisible(prm->get_draw()!=2);
            connect (render_epsilonSlider, SIGNAL(sliderMoved(int)), prm, SLOT(set_epsilon(int)));
            renderLayout->addWidget(render_epsilonSlider);

            // lightning (checkbox)
            render_lightingCheckBox = new QCheckBox ("Lighting");
            render_lightingCheckBox->setChecked(prm->get_lighting());
            connect(render_lightingCheckBox, SIGNAL (toggled (bool)), viewer, SLOT(set_lighting(bool)));
            renderLayout->addWidget(render_lightingCheckBox);

            // trianglescolor (checkbox)
            render_trianglescolorCheckBox = new QCheckBox ("Color per Triangles");
            render_trianglescolorCheckBox->setChecked(prm->get_trianglescolor());
            connect(render_trianglescolorCheckBox, SIGNAL (toggled (bool)), prm, SLOT(set_trianglescolor(bool)));
            renderLayout->addWidget(render_trianglescolorCheckBox);

            // grad (checkbox)
            render_gradCheckBox = new QCheckBox ("Gradient");
            render_gradCheckBox->setChecked(prm->get_grad());
            connect(render_gradCheckBox, SIGNAL (toggled (bool)), prm, SLOT(set_grad(bool)));
            renderLayout->addWidget(render_gradCheckBox);

            // brain (pushbutton)
            QPushButton * render_brainButton  = new QPushButton ("Brain render");
            connect (render_brainButton, SIGNAL (clicked()) , this, SLOT (set_brain()));
            renderLayout->addWidget (render_brainButton);

            // lines (pushbutton)
            QPushButton * render_linesButton  = new QPushButton ("Lines render");
            connect (render_linesButton, SIGNAL (clicked()) , this, SLOT (set_lines()));
            renderLayout->addWidget (render_linesButton);

            // background (pushbutton)
            QPushButton * render_bgButton  = new QPushButton ("Background render");
            connect (render_bgButton, SIGNAL (clicked()) , this, SLOT (set_bg()));
            renderLayout->addWidget (render_bgButton);

        renderGroupBox->setVisible(false);
        controlLayout->addWidget (renderGroupBox);
        controlLayout->addStretch (0);


        // EPOC GROUP_BOX
        // ----------------------------------------------

        epocLabel = new QGroupBox("Epoc Settings", controlWidget);
        epocLabel->setFixedWidth(prm->get_controlwidth());
        controlLayout->addWidget(epocLabel);

        epocGroupBox = new QGroupBox ("Epoc Settings", controlWidget);
        epocGroupBox->setFixedWidth(prm->get_controlwidth());
        QVBoxLayout * epocLayout = new QVBoxLayout (epocGroupBox);

            // key (combobox)
            epoc_keyComboBox = new QComboBox();
            epoc_keyComboBox->addItem("CONSUMER_HEADSET");
            epoc_keyComboBox->addItem("RESEARCH_HEADSET");
            epoc_keyComboBox->addItem("SPECIAL_HEADSET");
            epoc_keyComboBox->setCurrentIndex(prm->get_key());
            connect(epoc_keyComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(set_key(int)));
            epoc_keyComboBox->setDisabled(prm->get_started());
            epocLayout->addWidget(epoc_keyComboBox);

            // pvid (combobox)
            epoc_pvidComboBox = new QComboBox();
            epoc_pvidComboBox->addItem("NORMAL_ID");
            epoc_pvidComboBox->addItem("NEW_ID");
            epoc_pvidComboBox->setCurrentIndex(prm->get_pvid());
            connect(epoc_pvidComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(set_pvid(int)));
            epoc_pvidComboBox->setDisabled(prm->get_started());
            epocLayout->addWidget(epoc_pvidComboBox);

            // num (combobox)
            epoc_numComboBox = new QComboBox();
            epoc_numComboBox->setCurrentIndex(prm->get_numepoc());
            connect(epoc_numComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(set_numepoc(int)));
            epoc_numComboBox->setDisabled(prm->get_started());
            epocLayout->addWidget(epoc_numComboBox);

            // started (pushbutton)
            if(prm->get_started())  epoc_startedButton  = new QPushButton ("Stop");
            else                    epoc_startedButton  = new QPushButton ("Start");
            connect (epoc_startedButton, SIGNAL (clicked()) , this, SLOT(set_started()));
            update_numepocs();                              //do it here, so there's no segfault because of the startedButton
            epocLayout->addWidget (epoc_startedButton);

            // x (checkbox)
            epoc_xCheckBox = new QCheckBox ("X");
            epoc_xCheckBox->setChecked(prm->get_x());
            connect(epoc_xCheckBox, SIGNAL (toggled (bool)), this, SLOT(set_x(bool)));
            epocLayout->addWidget(epoc_xCheckBox);

            // y (checkbox)
            epoc_yCheckBox = new QCheckBox ("Y");
            epoc_yCheckBox->setChecked(prm->get_y());
            connect(epoc_yCheckBox, SIGNAL (toggled (bool)), this, SLOT(set_y(bool)));
            epocLayout->addWidget(epoc_yCheckBox);

            // acceleration (checkbox)
            epoc_accelerarionCheckBox = new QCheckBox ("acceleration");
            epoc_accelerarionCheckBox->setChecked(prm->get_acceleration());
            connect(epoc_accelerarionCheckBox, SIGNAL (toggled (bool)), this, SLOT(set_acceleration(bool)));
            epocLayout->addWidget(epoc_accelerarionCheckBox);

        epocGroupBox->setVisible(false);
        controlLayout->addWidget (epocGroupBox);
        controlLayout->addStretch (0);


        // FILE GROUPBOX
        // ----------------------------------------------

        fileLabel = new QGroupBox("File Settings", controlWidget);
        fileLabel->setFixedWidth(prm->get_controlwidth());
        controlLayout->addWidget(fileLabel);

        fileGroupBox = new QGroupBox ("File Settings", controlWidget);
        fileGroupBox->setFixedWidth(prm->get_controlwidth());
        QVBoxLayout * fileLayout = new QVBoxLayout (fileGroupBox);

            // save (pushbutton)
            file_saveButton  = new QPushButton ("Save");
            connect (file_saveButton, SIGNAL (clicked()) , this, SLOT (file_save()));
            fileLayout->addWidget (file_saveButton);

            // open (pushbutton)
            file_openButton  = new QPushButton ("Open");
            connect (file_openButton, SIGNAL (clicked()) , this, SLOT (file_open()));
            fileLayout->addWidget (file_openButton);

            // stop (pushbutton)
            file_stopButton  = new QPushButton ("Stop");
            connect (file_stopButton, SIGNAL (clicked()) , this, SLOT (file_stop()));
            file_stopButton->setVisible(false);
            fileLayout->addWidget (file_stopButton);

        fileGroupBox->setVisible(false);
        controlLayout->addWidget (fileGroupBox);
        controlLayout->addStretch (0);


        // SENSORS GROUP_BOX
        // ----------------------------------------------

        sensorsLabel = new QGroupBox("Sensors Settings", controlWidget);
        sensorsLabel->setFixedWidth(prm->get_controlwidth());
        controlLayout->addWidget(sensorsLabel);

        sensorsGroupBox = new QGroupBox ("Sensors Settings", controlWidget);
        sensorsGroupBox->setFixedWidth(prm->get_controlwidth());
        QVBoxLayout * sensorsLayout = new QVBoxLayout (sensorsGroupBox);

            // speedx (spinbox)
            sensorsLayout->addWidget(new QLabel("speed"));
            sensors_xspeedSpinBox = new QSpinBox();
            sensors_xspeedSpinBox->setMaximum(1000000);
            sensors_xspeedSpinBox->setValue(prm->get_xspeed());
            connect (sensors_xspeedSpinBox, SIGNAL (valueChanged (int)), prm, SLOT(set_xspeed(int)));
            sensorsLayout->addWidget(sensors_xspeedSpinBox);

            // speedy (spinbox)
            sensors_yspeedSpinBox = new QSpinBox();
            sensors_yspeedSpinBox->setMaximum(1000000);
            sensors_yspeedSpinBox->setValue(prm->get_yspeed());
            connect (sensors_yspeedSpinBox, SIGNAL (valueChanged (int)), prm, SLOT(set_yspeed(int)));
            sensorsLayout->addWidget(sensors_yspeedSpinBox);

            // sensors
            // all (pushbutton)
            if(prm->get_all()) sensors_allButton  = new QPushButton ("Uncheck all");
            else             sensors_allButton  = new QPushButton ("Check all");
            connect (sensors_allButton, SIGNAL (clicked()) , this, SLOT (set_all()));
            sensorsLayout->addWidget (sensors_allButton);

            eegcoord * egc = eegcoord::getInstance();
            for(int i=0; i<eegcoord::ntheta; i++){
                for(int j=0; j<eegcoord::nphi; j++){
                    if(egc->sensor[i][j]){
                        // sensor (checkbox)
                        sensors_CheckBox[i][j] = new checkbox(i,j,egc->labeli[i]+egc->labelj[j]);
                        sensors_CheckBox[i][j]->setChecked(eegcoord::getInstance()->sensor[i][j]);
                        connect(sensors_CheckBox[i][j], SIGNAL(clicked(bool)), this, SLOT(set_sensorCheckBox(bool)));
                        sensorsLayout->addWidget(sensors_CheckBox[i][j]);

                        // c (spinbox)
                        sensors_cSpinBox[i][j] = new spinbox(i,j);
                        sensors_cSpinBox[i][j]->setRange(7000,10000);
                        sensors_cSpinBox[i][j]->setValue(prm->get_c(i,j));
                        connect (sensors_cSpinBox[i][j], SIGNAL(valueChanged (int)), this, SLOT(set_cSpinBox(int)));
                        sensors_cSpinBox[i][j]->setVisible(!prm->get_slider());
                        sensorsLayout->addWidget(sensors_cSpinBox[i][j]);
                        // c (slider)
                        sensors_cSlider[i][j] = new slider(i,j);
                        sensors_cSlider[i][j]->setRange(7000,10000);
                        sensors_cSlider[i][j]->setValue(prm->get_c(i,j));
                        connect(sensors_cSlider[i][j], SIGNAL(sliderMoved(int)),this,SLOT(set_cSlider(int)));
                        sensors_cSlider[i][j]->setVisible(prm->get_slider());
                        sensorsLayout->addWidget(sensors_cSlider[i][j]);

                        // r (spinbox)
                        sensors_rSpinBox[i][j] = new spinbox(i,j);
                        sensors_rSpinBox[i][j]->setRange(50,500);
                        sensors_rSpinBox[i][j]->setValue(prm->get_r(i,j));
                        connect (sensors_rSpinBox[i][j], SIGNAL(valueChanged(int)), this, SLOT(set_rSpinBox(int)));
                        sensors_rSpinBox[i][j]->setVisible(!prm->get_slider());
                        sensorsLayout->addWidget(sensors_rSpinBox[i][j]);
                        // r (slider)
                        sensors_rSlider[i][j] = new slider(i,j);
                        sensors_rSlider[i][j]->setRange(50,500);
                        sensors_rSlider[i][j]->setValue(prm->get_r(i,j));
                        connect(sensors_rSlider[i][j], SIGNAL(sliderMoved(int)),this,SLOT(set_rSlider(int)));
                        sensors_rSlider[i][j]->setVisible(prm->get_slider());
                        sensorsLayout->addWidget(sensors_rSlider[i][j]);
                    }
                }
            }

        sensorsGroupBox->setVisible(false);
        controlLayout->addWidget (sensorsGroupBox);
        controlLayout->addStretch (0);


        // QUIT GROUP_BOX
        // ----------------------------------------------

            controlLayout->addWidget(new QLabel());
            // reset (pushbutton)
            QPushButton * resetButton  = new QPushButton ("Reset");
            resetButton->setFixedWidth(prm->get_controlwidth());
            connect (resetButton, SIGNAL (clicked()) , this, SLOT(reset()));
            controlLayout->addWidget(resetButton);

            // quit (pushbutton)
            QPushButton * quitButton  = new QPushButton ("Quit");
            quitButton->setFixedWidth(prm->get_controlwidth());
            connect (quitButton, SIGNAL (clicked()) , qApp, SLOT (closeAllWindows()));
            controlLayout->addWidget(quitButton);

    controlScroll->setWidget(controlWidget);
    controlScroll->setFixedWidth(controlWidget->width()+20);
    mainLayout->addWidget(controlScroll);

    setCentralWidget (mainGroupBox);

    setMinimumWidth (800);
    setMinimumHeight (400);
}

window::~window () {

}
