#include "widget.h"
#include <QResource>
#include <iostream>
#define GL_SILENCE_DEPRECATION
//#include <GLFW/glfw3.h>

OpenGLWidget::OpenGLWidget(s21::Settings &settings,
                           s21::Controller &controller, QWidget *parent)
    : settings_(settings),
      controller_(controller),
      QOpenGLWidget(parent) {
}

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

//void OpenGLWidget::MoveModel()
//{

//    model_view_matrix_.setToIdentity();
//    controller_.Scale(model_view_matrix_, settings_.scale);
//    controller_.Rotate(model_view_matrix_, settings_.rotation_x, settings_.rotation_y, settings_.rotation_z);
//    controller_.Translate(model_view_matrix_, settings_.translation_x, settings_.translation_y, settings_.translation_z);
//}

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
  GLenum glError = glGetError();
  if (glError != GL_NO_ERROR) {
      std::cout << glError << std::endl;
  }
  /*----------------------------------------------------------------------------------------------------------------------*/
  controller_.ShaderVersion() == 1 ? shader_programm_.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/resources/VertexShader.txt") :
                                     shader_programm_.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/resources/VertexShaderCPU.txt");
  std::cout << "/t My shader version is :" << controller_.ShaderVersion() << std::endl;
  shader_programm_.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/resources/FragShader.txt");
  shader_programm_.addShaderFromSourceFile(QOpenGLShader::Geometry, ":/resources/GeometryShader.txt");
  shader_programm_.link();
  shader_programm_.bind();
  /*----------------------------------------------------------------------------------------------------------------------*/
  shader_programm_.setUniformValue("color", settings_.color);
  shader_programm_.setUniformValue("lineWidth", 20);
  /*----------------------------------------------------------------------------------------------------------------------*/
  glGenBuffers(1, &vertex_buffer_); //vertex_buffer_object
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * controller_.GetVertexCopyConstRef().size(),
               controller_.GetVertexCopyConstRef().data(), GL_STATIC_DRAW);
  glGenBuffers(1, &index_buffer_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * controller_.GetFaceConstRef().size(), controller_.GetFaceConstRef().data(),
               GL_STATIC_DRAW);
  GLuint vao = 0;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  /*----------------------------------------------------------------------------------------------------------------------*/
  shader_programm_.release();
  /*----------------------------------------------------------------------------------------------------------------------*/
}

void OpenGLWidget::resizeGL(int w, int h) {
  /*----------------------------------------------------------------------------------------------------------------------*/
  glViewport(0, 0, w, h);
  projection_matrix_.setToIdentity();
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
  shader_programm_.setUniformValue("projectionMatrix", projection_matrix_);
  controller_.MoveModel(model_view_matrix_, settings_);
  shader_programm_.setUniformValue("modelViewMatrix", model_view_matrix_); //add if
  shader_programm_.setUniformValue("color", settings_.color);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);

  if(controller_.ShaderVersion() == 2){
      glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
      glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * controller_.GetVertexCopyConstRef().size(),
                   controller_.GetVertexCopyConstRef().data(), GL_STATIC_DRAW);
  }

    glDrawElements(GL_LINES, controller_.GetFaceConstRef().size(), GL_UNSIGNED_INT, nullptr);
  shader_programm_.release();

} //move everything from init and paint to its own functions
