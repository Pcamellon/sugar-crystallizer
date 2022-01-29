#include "sugar_crystallizer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  SugarCrystallizer w;
  w.show();

  return a.exec();
}
