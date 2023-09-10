#include "widget.h"

#include <QResource>
#include <iostream>

OpenGLWidget::OpenGLWidget(s21::Settings &settings, s21::Controller &controller,
                           QWidget *parent)
    : settings_(settings),
      controller_(controller),
      QOpenGLWidget(parent),
      vbo_(QOpenGLBuffer::VertexBuffer),
      ibo_(QOpenGLBuffer::IndexBuffer) {}

OpenGLWidget::~OpenGLWidget() { delete shader_version_; }

void OpenGLWidget::ChangeShaders() {
  shader_programm_.removeAllShaders();
  delete shader_version_;
  AddShaders();
  shader_programm_.link();
  update();
}

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

void OpenGLWidget::AddShaders() {
  shader_version_ = shader_factory_.create(settings_.shader_version);
  shader_programm_.addShaderFromSourceFile(
      QOpenGLShader::Vertex,
      shader_version_->GetVertexShader(controller_.GetVertexShaderVersion()));
  shader_programm_.addShaderFromSourceFile(
      QOpenGLShader::Geometry, shader_version_->GetGeometryShader());
  shader_programm_.addShaderFromSourceFile(
      QOpenGLShader::Fragment, shader_version_->GetFragmentShader());
}

void OpenGLWidget::ChangePerspective() {
  resizeGL(OpenGLWidget::width(), OpenGLWidget::height());
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) last_mouse_pos_ = event->pos();
  if (event->button() == Qt::RightButton) last_rmouse_pos_ = event->pos();
}

void OpenGLWidget::wheelEvent(QWheelEvent *event) {
  settings_.translation_z -=
      static_cast<float>(event->angleDelta().y()) / 120.0f;
  update();
}

void OpenGLWidget::initializeGL() {
  glClearColor(settings_.back_color.redF(), settings_.back_color.greenF(),
               settings_.back_color.blueF(), settings_.back_color.alphaF());
  glEnable(GL_DEPTH_TEST);

  AddShaders();
  shader_programm_.link();
  shader_programm_.bind();

  shader_programm_.setUniformValue("pointColor", settings_.vertex_color);
  shader_programm_.setUniformValue("lineColor", settings_.color);

  vbo_.create();
  vbo_.bind();
  vbo_.allocate(controller_.GetVertexCopyConstRef().data(),
                controller_.GetVertexCopyConstRef().size() * sizeof(GLfloat));
  vbo_.setUsagePattern(QOpenGLBuffer::StaticDraw);

  ibo_.create();
  ibo_.bind();
  ibo_.allocate(controller_.GetFaceConstRef().data(),
                controller_.GetFaceConstRef().size() * sizeof(GLuint));
  ibo_.setUsagePattern(QOpenGLBuffer::StaticDraw);

  vao_.create();
  vao_.bind();
  int vertex_location = shader_programm_.attributeLocation("position");
  shader_programm_.enableAttributeArray(vertex_location);
  shader_programm_.setAttributeBuffer(vertex_location, GL_FLOAT, 0, 3);
  vbo_.release();
  vao_.release();
  ibo_.release();
  shader_programm_.release();
}

void OpenGLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  projection_matrix_.setToIdentity();
  settings_.orth
      ? projection_matrix_.ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f)
      : projection_matrix_.perspective(60.0f, static_cast<float>(w) / (h), 0.1f,
                                       100.0f);
}

void OpenGLWidget::paintGL() {
  glClearColor(settings_.back_color.redF(), settings_.back_color.greenF(),
               settings_.back_color.blueF(), settings_.back_color.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  shader_programm_.bind();
  shader_programm_.setUniformValue("projectionMatrix", projection_matrix_);
  controller_.MoveModel(model_view_matrix_, settings_);
  shader_programm_.setUniformValue("lineWidth", settings_.line_width);
  shader_programm_.setUniformValue("pointWidth", settings_.point_size);
  shader_programm_.setUniformValue("showVertex", settings_.vertexes_shown);
  shader_programm_.setUniformValue("smoothVertex", settings_.smooth_vertexes);
  shader_programm_.setUniformValue("showLines", settings_.lines_shown);
  shader_programm_.setUniformValue("edgedLines", settings_.broken_lines);
  shader_programm_.setUniformValue("modelViewMatrix", model_view_matrix_);

  shader_programm_.setUniformValue("pointColor", settings_.vertex_color);
  shader_programm_.setUniformValue("lineColor", settings_.color);

  vao_.bind();
  ibo_.bind();

  if (controller_.GetVertexShaderVersion() == 2) {
    vbo_.bind();
    vbo_.allocate(controller_.GetVertexCopyConstRef().data(),
                  controller_.GetVertexCopyConstRef().size() * sizeof(GLfloat));
    vbo_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo_.release();
  }

  glDrawElements(GL_LINES, controller_.GetFaceConstRef().size(),
                 GL_UNSIGNED_INT, nullptr);
  ibo_.release();
  vao_.release();
  shader_programm_.release();
}
