#include "widget.h"

#include <iostream>

OpenGLWidget::OpenGLWidget(s21::Settings &settings,
                           s21::Controller &controller, QWidget *parent)
    : settings_(settings),
      controller_(controller),
      QOpenGLWidget(parent) {}

OpenGLWidget::~OpenGLWidget() { std::cout << "ustroy destroy" << std::endl; }

void OpenGLWidget::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    QPoint delta = event->pos() - last_mouse_pos_;
    settings_.rotation_x += delta.x();
    settings_.rotation_y += delta.y();
    update();
    last_mouse_pos_ = event->pos();
  } else if (event->buttons() & Qt::RightButton) {
    QPoint delta = event->pos() - last_rmouse_pos_;
    settings_.translation_x += delta.x() / 100.0f;
    settings_.translation_y -= delta.y() / 100.0f;
    update();
    last_rmouse_pos_ = event->pos();
  }
}

void OpenGLWidget::MoveModel()
{

    model_view_matrix_.setToIdentity();
    controller_.Scale(model_view_matrix_, settings_.scale);
    controller_.Rotate(model_view_matrix_, settings_.rotation_x, settings_.rotation_y, settings_.rotation_z);
    controller_.Translate(model_view_matrix_, settings_.translation_x, settings_.translation_y, settings_.translation_z);
}

// void OpenGLWidget::translateModel(int direction, float amount) {
//   if (direction == 0)
//     translationY += amount;
//   else if (direction == 1)
//     translationX += amount;
//   else if (direction == 2)
//     translationY -= amount;
//   else if (direction == 3)
//     translationX -= amount;
//   else if (direction == 4)
//     translationZ -= amount;
//   else if (direction == 5)
//     translationZ += amount;
//   update();
// }

// void OpenGLWidget::RotateModel(int direction, float amount) {
//   if (direction == 0)
//     settings_.rotation_y += amount;
//   else if (direction == 1)
//     settings_.rotation_x += amount;
//   else if (direction == 2)
//     settings_.rotation_y -= amount;
//   else if (direction == 3)
//     settings_.rotation_x -= amount;
//   else if (direction == 4)
//     settings_.rotation_z -= amount;
//   else if (direction == 5)
//     settings_.rotation_z += amount;
//   update();
// }

// void OpenGLWidget::ceterModel() {
//   translationZ = -m_medianZ * scaleBy;
//   translationX = -m_medianX * scaleBy;
//   translationY = -m_medianY * scaleBy;
//   update();
// }


void OpenGLWidget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) last_mouse_pos_ = event->pos();
  if (event->button() == Qt::RightButton) last_rmouse_pos_ = event->pos();
}

void OpenGLWidget::wheelEvent(QWheelEvent *event) {
  settings_.translation_z -= static_cast<float>(event->angleDelta().y()) / 120.0f;
  update();
}

void OpenGLWidget::initializeGL() {
  glClearColor(settings_.back_color.redF(), settings_.back_color.greenF(),
               settings_.back_color.blueF(), settings_.back_color.alphaF());
  glEnable(GL_DEPTH_TEST);
  /*----------------------------------------------------------------------------------------------------------------------*/
  shader_programm_.addShaderFromSourceCode(QOpenGLShader::Vertex,
                                           vertexShaderSource);
  shader_programm_.addShaderFromSourceCode(QOpenGLShader::Fragment,
                                           fragmentShaderSource);
  shader_programm_.link();
  shader_programm_.bind();
  /*----------------------------------------------------------------------------------------------------------------------*/
  shader_programm_.setUniformValue("color", settings_.color);
  /*----------------------------------------------------------------------------------------------------------------------*/
  glGenBuffers(1, &vertex_buffer_); //vertex_buffer_object
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * controller_.GetVertexCopyConstRef().size(),
               controller_.GetVertexCopyConstRef().data(), GL_STATIC_DRAW);
  glGenBuffers(1, &index_buffer_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * controller_.GetFaceConstRef().size(),
               controller_.GetFaceConstRef().data(), GL_STATIC_DRAW);  // вынести в метов
  /*----------------------------------------------------------------------------------------------------------------------*/

  GLuint positionLocation = shader_programm_.attributeLocation("position");
  glEnableVertexAttribArray(positionLocation);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
  glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
  shader_programm_.release();
  /*----------------------------------------------------------------------------------------------------------------------*/
}

void OpenGLWidget::resizeGL(int w, int h) {
  /*----------------------------------------------------------------------------------------------------------------------*/
  glViewport(0, 0, w, h);
  projection_matrix_.setToIdentity();
  //  ortho ? projectionMatrix.ortho(m_minX < 0 ? m_minX * 2 : m_minX / 2,
  //                                 m_maxX > 0 ? m_maxX * 2 : m_maxX / 2,
  //                                 m_minY < 0 ? m_minY * 2 : m_minY / 2,
  //                                 m_maxY > 0 ? m_maxY * 2 : m_maxY / 2,
  //                                 m_minZ < 0 ? m_minZ * 2 : m_minZ / 2,
  //                                 m_maxZ > 0 ? m_maxZ * 2 : m_maxZ / 2)
  projection_matrix_.perspective(60.0f, static_cast<float>(w) / (h), 0.1f,
                                 100.0f);
  /*----------------------------------------------------------------------------------------------------------------------*/
}

void OpenGLWidget::paintGL() {
  /*----------------------------------------------------------------------------------------------------------------------*/
  glClearColor(settings_.back_color.redF(), settings_.back_color.greenF(),
               settings_.back_color.blueF(), settings_.back_color.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  shader_programm_.bind();
  shader_programm_.setUniformValue("dashed", false);
  shader_programm_.setUniformValue("projectionMatrix", projection_matrix_);
  MoveModel();
  shader_programm_.setUniformValue("modelViewMatrix", model_view_matrix_);

  glLineWidth(static_cast<float>(settings_.line_width));
  glPointSize(settings_.point_size);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);
  settings_.smooth_vertexes ? glEnable(GL_POINT_SMOOTH)
                            : glDisable(GL_POINT_SMOOTH);
  if (settings_.vertexes_shown) {
    shader_programm_.setUniformValue("color", settings_.vertex_color);
    glDrawElements(GL_POINTS, controller_.GetFaceConstRef().size(), GL_UNSIGNED_INT, nullptr);
  }
  shader_programm_.setUniformValue("color", settings_.color);
  settings_.broken_lines ? shader_programm_.setUniformValue("dashed", true)
                         : shader_programm_.setUniformValue("dashed", false);

  if (settings_.lines_shown)
    glDrawElements(GL_LINES, controller_.GetFaceConstRef().size(), GL_UNSIGNED_INT, nullptr);
  shader_programm_.release();
  /*----------------------------------------------------------------------------------------------------------------------*/
}
