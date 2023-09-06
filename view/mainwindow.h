#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMainWindow>
#include <QMovie>
#include <QProcess>
#include <QTimer>
#include <iostream>
#include "../model/model.h"
//#include "../controller/controller.h"
#include "widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow final : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(s21::Controller &controller, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void ChangeBackgroundColor();
  void ChangeLineColor();
  void ChangeVertexColor();
  void BrowseModel();
  void closeEvent(QCloseEvent *event) override;

 private:
  void ConnectToLambdas();
  void ConnectTranslateToLambdas();
  void ConnectRotateToLambdas();
  void UpdateWidget();
  OpenGLWidget *gl_widget_;
  Ui::MainWindow *ui_;
  s21::Controller &controller_;
  s21::Settings settings_;
};

#endif  // MAINWINDOW_H
