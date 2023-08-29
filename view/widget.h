#ifndef WIDGET_H
#define WIDGET_H

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <QTimer>
#include <QVector3D>
#include <QWidget>

#include "settings.h"

class OpenGLWidget final : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
 public:
  explicit OpenGLWidget(s21::Settings& settings, const QVector<float>& vertex,
                        const QVector<int>& face, QWidget* parent = nullptr);
  ~OpenGLWidget();

 protected:
 private:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  void mousePressEvent(QMouseEvent* event);
  void wheelEvent(QWheelEvent* event);
  void mouseMoveEvent(QMouseEvent* event);
  const QVector<float>& vertex_;
  const QVector<int>& face_;
  s21::Settings& settings_;
  QPoint last_mouse_pos_;
  QPoint last_rmouse_pos_;
  //  bool backgroundChanged;
  //  bool ortho;
  //  bool vertexRecolored;
  //  bool smoothVertexes;
  //  bool lineThicknessChanged;
  //  bool vertexesShown;
  //  bool linesShown;
  //  bool lineStrip;
  //  int scrollDelta;
  //  int lineThickness;
  //  int vertexThickness;
  //  bool vertexThicknessChanged;
  //  float m_medianX;
  //  float m_medianY;
  //  float m_medianZ;
  //  float m_minX;
  //  float m_maxX;
  //  float m_minY;
  //  float m_maxY;
  //  float m_minZ;
  //  float m_maxZ;
  QOpenGLShaderProgram shader_programm_;
  QMatrix4x4 projection_matrix_;
  QMatrix4x4 model_view_matrix_;
  //  GLuint texCoordLocation;
  GLuint index_buffer_;
  GLuint vertex_buffer_;
  //  GLuint textureBuffer;
  //  GLuint normalBuffer;
  GLfloat translation_x_ = 0;
  GLfloat translation_y_ = 0;
  GLfloat translation_z_ = 0;
  GLfloat rotation_x_ = 0;
  GLfloat rotation_y_ = 0;
  GLfloat rotation_z_ = 0;
  //  float scale_;
  const char* vertexShaderSource =
      "attribute vec3 position;\n"
      "uniform mat4 projectionMatrix;\n"
      "uniform mat4 modelViewMatrix;\n"
      "void main()\n"
      "{\n"
      "    gl_Position = projectionMatrix * modelViewMatrix * vec4(position, "
      "1.0);\n"
      "}\n";

  const char* fragmentShaderSource =
      "uniform vec4 color;\n"
      "uniform bool dashed;\n"
      "void main()\n"
      "{\n"
      "    if (dashed)\n"
      "    {\n"
      "        float dashSize = 0.3;\n"
      "        float gapSize = 0.3;\n"
      "        float t = mod(gl_FragCoord.x, (dashSize + gapSize)) / (dashSize "
      "+ gapSize);\n"
      "        if (t > 0.5)\n"
      "        {\n"
      "            gl_FragColor = color;\n"
      "        }\n"
      "        else\n"
      "        {\n"
      "            discard;\n"
      "        }\n"
      "    }\n"
      "    else\n"
      "    {\n"
      "        gl_FragColor = color;\n"
      "    }\n"
      "}\n";
};

#endif  // WIDGET_H
