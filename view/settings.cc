#include "settings.h"
namespace s21 {

Settings::Settings() {
  vertexes_shown = false;
  smooth_vertexes = true;
  broken_lines = false;
  lines_shown = true;
  orth = false;
  line_width = 1;
  point_size = 5;
  scale = 1.0f;
  color.setRgbF(1.0f, 1.0f, 1.0f, 1.0f);
  back_color.setRgbF(0.0f, 0.0f, 0.0f, 1.0f);
  vertex_color.setRgbF(1.0f, 0.0f, 1.0f, 1.0f);  // to default settings
  LoadSettings();
}

void Settings::SaveSettings() {
  QJsonObject settings;
  settings["color_r"] = color.red();
  settings["color_g"] = color.green();
  settings["color_b"] = color.blue();
  settings["color_a"] = color.alpha();
  settings["back_color_r"] = back_color.red();
  settings["back_color_g"] = back_color.green();
  settings["back_color_b"] = back_color.blue();
  settings["back_color_a"] = back_color.alpha();
  settings["vertex_color_r"] = vertex_color.red();
  settings["vertex_color_g"] = vertex_color.green();
  settings["vertex_color_b"] = vertex_color.blue();
  settings["vertex_color_a"] = vertex_color.alpha();
  settings["smooth_vertexes"] = smooth_vertexes;
  settings["vertexes_shown"] = vertexes_shown;
  settings["broken_lines"] = broken_lines;
  settings["lines_shown"] = lines_shown;
  settings["line_width"] = line_width;
  settings["point_size"] = point_size;
  settings["orth"] = orth;
  settings["scale"] = scale;

  QJsonDocument doc(settings);
  QFile file(static_cast<QDir>(QDir::homePath()).absolutePath() +
             "/Desktop/viewer/settings.json");
  if (file.open(QIODevice::WriteOnly)) {
    file.write(doc.toJson());
    file.close();
  }
}

void Settings::LoadSettings() {
  QFile file(static_cast<QDir>(QDir::homePath()).absolutePath() +
             "/Desktop/viewer/settings.json");

  if (file.open(QIODevice::ReadOnly)) {
    QJsonDocument jsonchik = QJsonDocument::fromJson(file.readAll());
    QJsonObject settings = jsonchik.object();

    color.setRed(settings.value("color_r").toInt());
    color.setGreen(settings.value("color_g").toInt());
    color.setBlue(settings.value("color_b").toInt());
    color.setAlpha(settings.value("color_a").toInt());
    back_color.setRed(settings.value("back_color_r").toInt());
    back_color.setGreen(settings.value("back_color_g").toInt());
    back_color.setBlue(settings.value("back_color_b").toInt());
    back_color.setAlpha(settings.value("back_color_a").toInt());
    vertex_color.setRed(settings.value("vertex_color_r").toInt());
    vertex_color.setGreen(settings.value("vertex_color_g").toInt());
    vertex_color.setBlue(settings.value("vertex_color_b").toInt());
    vertex_color.setAlpha(settings.value("vertex_color_a").toInt());
    orth = settings.value("orth").toBool();
    smooth_vertexes = settings.value("smooth_vertexes").toBool();
    vertexes_shown = settings.value("vertexes_shown").toBool();
    broken_lines = settings.value("broken_lines").toBool();
    lines_shown = settings.value("lines_shown").toBool();
    line_width = settings.value("line_width").toInt();
    point_size = settings.value("line_width").toInt();
    scale = settings.value("scale").toDouble();

    file.close();
  }
}
}  // namespace s21
