#include "settings.h"
namespace s21 {

Settings::Settings() {
  color.setRgbF(1.0f, 1.0f, 1.0f, 1.0f);
  back_color.setRgbF(0.0f, 0.0f, 0.0f, 1.0f);
  vertex_color.setRgbF(1.0f, 0.0f, 1.0f, 1.0f);  // to default settings
  light_color.setRgbF(1.0f, 0.0f, 1.0f, 1.0f);
//  LoadSettings();
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
  settings["light_color_r"] = light_color.red();
  settings["light_color_g"] = light_color.green();
  settings["light_color_b"] = light_color.blue();
  settings["light_color_a"] = light_color.alpha();
  settings["line_width"] = line_width;
  settings["point_size"] = point_size;
  settings["ambient"] = ambient;
  settings["specular"] = specular;
  settings["shader_version"] = shader_version;
  settings["wireframe"] = wireframe;
  settings["lights_on"] = lights_on;
  settings["flat_shading"] = flat_shading;
  settings["orth"] = orth;
  settings["vertexes_shown"] = vertexes_shown;
  settings["smooth_vertexes"] = smooth_vertexes;
  settings["lines_shown"] = lines_shown;
  settings["broken_lines"] = broken_lines;

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
    light_color.setRed(settings.value("light_color_r").toInt());
    light_color.setGreen(settings.value("light_color_g").toInt());
    light_color.setBlue(settings.value("light_color_b").toInt());
    light_color.setAlpha(settings.value("light_color_a").toInt());
    line_width = settings.value("line_width").toDouble();
    point_size = settings.value("point_size").toDouble();
    ambient = settings.value("ambient").toDouble();
    specular = settings.value("specular").toDouble();
    shader_version = static_cast<ShaderFactory::ShaderVersion>(
        settings.value("shader_version").toInt());
    wireframe = settings.value("wireframe").toBool();
    lights_on = settings.value("lights_on").toBool();
    flat_shading = settings.value("flat_shading").toBool();
    orth = settings.value("orth").toBool();
    vertexes_shown = settings.value("vertexes_shown").toBool();
    smooth_vertexes = settings.value("smooth_vertexes").toBool();
    lines_shown = settings.value("lines_shown").toBool();
    broken_lines = settings.value("broken_lines").toBool();

    file.close();
  }
}
}  // namespace s21
