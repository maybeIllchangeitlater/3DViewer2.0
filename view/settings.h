#ifndef CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
#define CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
// #include "ui_mainwindow.h"
// #include "mainwindow.h
// #include <QMainWindow>
#include <QCloseEvent>
#include <QColorDialog>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QOpenGLFunctions>
#include <iostream>

namespace s21 {
class Settings {
 public:
  Settings();
  void SaveSettings();
  void LoadSettings();
  QColor color;
  QColor back_color;
  QColor vertex_color;
  bool orth;
  bool smooth_vertexes;
  bool vertexes_shown;
  bool lines_shown;
  bool broken_lines;
  int line_width;
  int point_size;
  float scale;
  float translation_x = 0;
  float translation_y = 0;
  float translation_z = 0;
  float rotation_x = 0;
  float rotation_y = 0;
  float rotation_z = 0;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
