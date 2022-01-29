#include "cristalizadora.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Cristalizadora w;
  w.show();

  return a.exec();
}
