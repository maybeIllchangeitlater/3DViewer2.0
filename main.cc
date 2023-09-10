#include <QApplication>

#include "view/mainwindow.h"
#include "view/widget.h"

int main(int argc, char *argv[]) {
  s21::ObjParser p;
  s21::GPUTransformation t;
  //  s21::CPUTransformation t;
  s21::Controller c(p, &t);
  QApplication a(argc, argv);
  MainWindow w(c);
  w.LoadStyle();
  w.show();
  return a.exec();
}
