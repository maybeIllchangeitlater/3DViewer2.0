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
  bool orth;
  bool smooth_vertexes;
  bool vertexes_shown;
  bool lines_shown;
  bool broken_lines;
  float line_width = 0.01;
  float point_size = 0.01;
  float scale = 1.0;
  float translation_x = 0;
  float translation_y = 0;
  float translation_z = 0;
  float rotation_x = 0;
  float rotation_y = 0;
  float rotation_z = 0;
  ShaderFactory::ShaderVersion shader_version = ShaderFactory::kEverything;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
