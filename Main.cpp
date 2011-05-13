#include <QApplication>
#include <Window.h>
#include <QPlastiqueStyle>

using namespace std;

int main (int argc, char **argv)
{
  QApplication raymini (argc, argv);
  QApplication::setStyle (new QPlastiqueStyle);
  Window * window = new Window ();
  window->setWindowTitle ("RayMini: A minimal image synthesizer based on raytracing.");
  window->showMaximized ();
  window->show();
  raymini.connect (&raymini, SIGNAL (lastWindowClosed()), &raymini, SLOT (quit()));
  
  return raymini.exec ();
}

