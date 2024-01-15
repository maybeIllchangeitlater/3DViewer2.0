#ifndef CPP4_3DVIEWER_V2_0_VIEW_WIDGET_H_
#define CPP4_3DVIEWER_V2_0_VIEW_WIDGET_H_

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <QTimer>
#include <QVector3D>
#include <QWidget>
#include <memory>

#include "../controller/controller.h"
#include "settings.h"

class OpenGLWidget final : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit OpenGLWidget(s21::Settings& settings, s21::Controller& controller,
                        QWidget* parent = nullptr);
  ~OpenGLWidget();
  void ChangeShaders();
  void ChangePerspective();

 private:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  /**
   * @brief Saves mouse position on click
   */
  void mousePressEvent(QMouseEvent* event);
  /**
   * @brief Translation by Z
   */
  void wheelEvent(QWheelEvent* event);
  /**
   * @brief RMB - translation by xy, LMB - translation by xy
   */
  void mouseMoveEvent(QMouseEvent* event);
  void AddShaders();
  void ConfigureAttributeBuffers();
  void LightsOn();
  void CalculateCamera();
  void ConfigureDisplay();

  void DrawLight();

  s21::Settings& settings_;
  s21::Controller& controller_;
  QPoint last_mouse_pos_;
  QPoint last_rmouse_pos_;

  QOpenGLShaderProgram shader_programm_;
  QOpenGLShaderProgram shader_light_;
  QMatrix4x4 projection_matrix_;
  QMatrix4x4 model_view_matrix_;

  QOpenGLBuffer ibo_, ibo_light_;;
  QOpenGLBuffer vbo_, vbo_light_;
  QOpenGLVertexArrayObject vao_, vao_light_;

  GLuint index_buffer_;
  GLuint vertex_buffer_;

//  const s21::ShaderState* shader_version_ = nullptr;
  std::unique_ptr<s21::ShaderState> shader_version_;
  std::unique_ptr<QOpenGLTexture> texture_;
  s21::ShaderFactory shader_factory_;

  bool has_normales_ = false;
  bool has_texture_map_ = false;
};

#endif  // CPP4_3DVIEWER_V2_0_VIEW_WIDGET_H_
