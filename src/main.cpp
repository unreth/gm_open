#include <QApplication>
#include <QPlastiqueStyle>

#include "gui/window.h"

using namespace std;

int main (int argc, char **argv)
{
  QApplication gmopen (argc, argv);
  QApplication::setStyle (new QPlastiqueStyle);
  window * w = new window ();
  w->setWindowTitle ("gm_open");
  w->showMaximized ();
  w->show();
  gmopen.exec();
  
  return 0;
}
