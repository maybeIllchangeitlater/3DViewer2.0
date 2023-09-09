#ifndef WIDGET_H
#define WIDGET_H

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <QTimer>
#include <QVector3D>
#include <QWidget>

#include "../controller/controller.h"
#include "settings.h"

class OpenGLWidget final : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit OpenGLWidget(s21::Settings& settings, s21::Controller& controller,
                        QWidget* parent = nullptr);
  ~OpenGLWidget();
  void ChangeShaders();

 private:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  void mousePressEvent(QMouseEvent* event);
  void wheelEvent(QWheelEvent* event);
  void mouseMoveEvent(QMouseEvent* event);
  void AddShaders();

  s21::Settings& settings_;
  s21::Controller& controller_;
  QPoint last_mouse_pos_;
  QPoint last_rmouse_pos_;

  QOpenGLShaderProgram shader_programm_;
  QMatrix4x4 projection_matrix_;
  QMatrix4x4 model_view_matrix_;

  QOpenGLBuffer ibo_;
  QOpenGLBuffer vbo_;
  QOpenGLVertexArrayObject vao_;

  GLuint index_buffer_;
  GLuint vertex_buffer_;

  s21::ShaderState * shader_version_ = nullptr;
  s21::ShaderFactory shader_factory_;
};

#endif  // WIDGET_H
