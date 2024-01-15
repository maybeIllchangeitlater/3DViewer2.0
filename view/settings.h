#ifndef CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
#define CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
#include <QCloseEvent>
#include <QColorDialog>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include "ShaderFactory.h"

namespace s21 {
class Settings {
 public:
  Settings();
  void SaveSettings();
  void LoadSettings();
  QColor color;
  QColor back_color;
  QColor vertex_color;
  QColor light_color;
  QVector3D translation = {0, 0, 0};
  QVector3D rotation = {0, 0, 0};
  QVector3D camera = {0, 0, 0};
  QVector3D camera_up = {0, 0, 0};
  QVector3D light_position = {50, 0, -50};
  float line_width = 0.01;
  float point_size = 0.01;
  float scale = 1.0;
  float ambient = 0.1;
  float specular = 0.5;
  ShaderFactory::ShaderVersion shader_version = ShaderFactory::kEverything;
  bool wireframe = true;
  bool lights_on = false;
  bool flat_shading = true;
  bool orth = false;
  bool vertexes_shown = false;
  bool smooth_vertexes = false;
  bool lines_shown = true;
  bool broken_lines = false;

};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
