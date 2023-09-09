#include <QApplication>

#include "mainwindow.h"
#include "widget.h"

int main(int argc, char *argv[]) {
  s21::ObjParser p;
  s21::OpenGLTransformation t;
//  s21::CPUTransformation t;
//  s21::ShaderNoGeometry s;
  s21::ShaderPointsOnly s;
  s21::Controller c(p, &t, &s);
  QApplication a(argc, argv);
  MainWindow w(c);
  w.LoadStyle();
  w.show();
  return a.exec();
}
