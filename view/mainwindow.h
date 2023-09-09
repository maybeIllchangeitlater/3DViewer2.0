#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QFontDatabase>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMainWindow>
#include <QMenu>
#include <QMovie>
#include <QProcess>
#include <QSurface>
#include <QTextStream>
#include <QTimer>
#include <iostream>
#include <thread>
#include <QMovie>
#include <QImage>
#include <QPainter>

#include "../controller/controller.h"
#include "widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow final : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(s21::Controller &controller, QWidget *parent = nullptr);
  void LoadStyle();
  ~MainWindow();

 private slots:
  void ChangeBackgroundColor();
  void ChangeLineColor();
  void ChangeVertexColor();
  void BrowseModel();
  void closeEvent(QCloseEvent *event) override;
  void UpdateView(bool correct_file);
  void MakeScreenshot(int mode);
  void MakeGif();

 private:
  void CreateOpenGLContext();
  void ConnectToLambdas();
  void ConnectTranslateToLambdas();
  void ConnectRotateToLambdas();
  void UpdateWidget();
  void SetSliders();
  void SetShaderMenu();

  OpenGLWidget *gl_widget_;
  Ui::MainWindow *ui_;
  s21::Controller &controller_;
  s21::Settings settings_;

  int imagecounter = 0;
  int screenshotcounter = 0;

  QAction enable_uncustomizable_lines_;
  QAction enable_lines_;
  QAction enable_points_;
  QAction enable_everything_;
  QMenu shader_menu_;
};

#endif  // MAINWINDOW_H
