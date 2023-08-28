#include <QApplication>

#include "mainwindow.h"
#include "widget.h"

int main(int argc, char *argv[]) {
  s21::ObjParser p;
  s21::Controller c(p);
  QApplication a(argc, argv);
  MainWindow w(c);
  w.show();
  return a.exec();
}
