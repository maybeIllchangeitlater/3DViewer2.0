#ifndef CPP4_3DVIEWER_V2_0_VIEW_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_VIEW_MAINWINDOW_H_

#include <QCloseEvent>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QFontDatabase>
#include <QImage>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMainWindow>
#include <QMenu>
#include <QSurface>
#include <QTextStream>
#include <thread>

#include "../controller/controller.h"
#include "view/3rdParty/gifmaker/gif_hash.h"
#include "view/3rdParty/gifmaker/gif_lib.h"
#include "view/3rdParty/gifmaker/gif_lib_private.h"
#include "view/3rdParty/gifmaker/qgifglobal.h"
#include "view/3rdParty/gifmaker/qgifimage.h"
#include "view/3rdParty/gifmaker/qgifimage_p.h"
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

 private:
  enum ScreenShotMode { kJpeg, kBMP };
  void CreateOpenGLContext();
  void ConnectToLambdas();
  void ConnectTranslateToLambdas();
  void ConnectRotateToLambdas();
  void UpdateWidget();
  void SetSliders() noexcept;
  void SetShaderMenu();
  void CompileAndSaveGif();

  OpenGLWidget *gl_widget_;
  Ui::MainWindow *ui_;
  s21::Controller &controller_;
  s21::Settings settings_;
  int screenshotcounter_ = 0;
  QVector<QImage> image_;
  QTimer timer_;

  QAction enable_uncustomizable_lines_;
  QAction enable_lines_;
  QAction enable_points_;
  QAction enable_everything_;
  QMenu shader_menu_;

 private slots:
  void BrowseModel();
  void closeEvent(QCloseEvent *event) override;
  void UpdateView(bool correct_file);
  void ChangeBackgroundColor();
  void ChangeLineColor();
  void ChangeVertexColor();
  void MakeScreenshot(enum ScreenShotMode mode);
  void MakeGif();
};

#endif  //CPP4_3DVIEWER_V2_0_VIEW_MAINWINDOW_H_
