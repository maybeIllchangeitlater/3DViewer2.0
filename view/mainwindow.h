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
//  void translateBy(float x,float y);
//  void RotateBy();


 private:
  void ConnectToLambdas();
  void ConnectTranslateToLambdas();
  void ConnectRotateToLambdas();
  void UpdateWidget();
  OpenGLWidget *gl_widget_;
  Ui::MainWindow *ui_;
  s21::Controller &controller_;
  s21::Settings settings_;
  //  QList<QImage> jiff;
  //  int imagecounter;
  //  int screenshotcounter;
  //  int maxface;
  //  QDir dir;
  //  QString filename;
  //  QColor color;
  //  QColor back_color;
  //  QColor vertex_color;
  //  bool showLines;
  //  bool smoothVertexes;
  //  bool vertexesShown;
  //  bool brokenEdges;
  //  bool orth;
  //  float minx = 0, miny = 0, minz = 0, maxx = 0, maxy = 0, maxz = 0;
  //  Gigachad bigstructarray = {0};
  //  float medianX, medianY, medianZ;
  //  std::vector<GLfloat> vertexPositions;
  //  std::vector<GLuint> indices;
  //  int lineW;
  //  int vertexW;
  //  QTimer timer;
};

#endif  // MAINWINDOW_H
