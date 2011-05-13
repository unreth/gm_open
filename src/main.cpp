#include <QApplication>
#include <QPlastiqueStyle>

#include "gui/window.h"

using namespace std;

int main (int argc, char **argv)
{
  QApplication raymini (argc, argv);
  QApplication::setStyle (new QPlastiqueStyle);
  window * w = new window ();
  w->setWindowTitle ("RayMini: A minimal image synthesizer based on raytracing.");
  w->showMaximized ();
  w->show();
  raymini.connect (&raymini, SIGNAL (lastWindowClosed()), &raymini, SLOT (quit()));
  
  return raymini.exec ();
}

