#ifndef WINDOW_H
#define WINDOW_H

#include <QAction>
#include <QColorDialog>
#include <QGroupBox>
#include <QLabel>
#include <QLayout>
#include <QMainWindow>
#include <QPushButton>

#include "GLViewer.h"

class Window : public QMainWindow {
    Q_OBJECT
public:
    Window();
    virtual ~Window();

    static void showStatusMessage (const QString & msg);  
    
public slots :
    void renderRayImage ();
    void setBGColor ();
    
private :
    
    QActionGroup * actionGroup;
    QString currentDirectory;

    GLViewer * viewer;
    QLabel * imageLabel;
    QImage rayImage;

    QPushButton * rayButton;
};

#endif // WINDOW_H
