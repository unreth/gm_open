#include "Window.h"

using namespace std;

Window::Window () : QMainWindow (NULL) {
    try {
        viewer = new GLViewer;
    } catch (GLViewer::Exception e) {
        cerr << e.getMessage () << endl;
        exit (1);
    }
    QGroupBox * renderingGroupBox = new QGroupBox (this);
    QHBoxLayout * renderingLayout = new QHBoxLayout (renderingGroupBox);
    
    renderingLayout->addWidget (viewer);
    setCentralWidget (renderingGroupBox);
    
    setMinimumWidth (800);
    setMinimumHeight (400);
}

Window::~Window () {

}

void Window::renderRayImage () {
    
}

void Window::setBGColor () {
    QColor c = QColorDialog::getColor (QColor (133, 152, 181), this);
    if (c.isValid () == true) {
        cout << c.red () << endl;
        viewer->setBackgroundColor (c);
        viewer->updateGL ();
    }
}
