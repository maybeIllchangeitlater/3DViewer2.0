#include <QApplication>

#include "mainwindow.h"
//#include "widget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model m;
  s21::Controller c(m);
  MainWindow w(c);
  w.show();
  return a.exec();
}
