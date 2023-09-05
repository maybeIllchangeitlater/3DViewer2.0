#include <QApplication>

#include "mainwindow.h"
#include "widget.h"

int main(int argc, char *argv[]) {
  s21::ObjParser p;//qsurfaces .setcontext version
  s21::OpenGLTransformation t;
//  s21::CPUTransformation t;
  s21::Controller c(p, &t);
  QApplication a(argc, argv);
  MainWindow w(c);
  w.show();
  return a.exec();
}
