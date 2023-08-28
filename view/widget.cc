#include "widget.h"

#include <iostream>

OpenGLWidget::OpenGLWidget(const QVector<float> &vertex, const QVector<int> &face, QWidget* parent)
    :vertex_(vertex),face_(face), QOpenGLWidget(parent) {}

OpenGLWidget::~OpenGLWidget() { std::cout<< "ustroy destroy" << std::endl;}

//void OpenGLWidget::setEdgesColorAndUpdate(QColor t_color) {
//  m_color = t_color;
//  shaderProgram.bind();
//  shaderProgram.setUniformValue("color", m_color);
//  shaderProgram.release();
//  update();
//}

//void OpenGLWidget::setBackgroundColorAndUpdate(QColor b_color) {
//  backgroundChanged = m_back_color == b_color ? false : true;
//  m_back_color = b_color;
//  update();
//}

//void OpenGLWidget::setVertexColorAndUpdate(QColor v_color) {
//  m_vertex_color = v_color;
//  update();
//}

//void OpenGLWidget::scaleModel(int position) {
//  scaleBy = static_cast<float>(position) / 100;
//  update();
//}

//void OpenGLWidget::scaleLines(int scale) {
//  lineThickness = scale;
//  lineThicknessChanged = true;
//  update();
//}

//void OpenGLWidget::scaleVertex(int position) {
//  vertexThickness = position;
//  vertexThicknessChanged = true;
//  update();
//}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    QPoint delta = event->pos() - last_mouse_pos_;
    rotation_x_ += delta.x();
    rotation_y_ += delta.y();
    update();
    last_mouse_pos_ = event->pos();
  } else if (event->buttons() & Qt::RightButton) {
    QPoint delta = event->pos() - last_mouse_pos_;
    translation_x_ += delta.x() / 100.0f;
    translation_y_ -= delta.y() / 100.0f;
    update();
    last_rmouse_pos_ = event->pos();
  }
}

//void OpenGLWidget::translateModel(int direction, float amount) {
//  if (direction == 0)
//    translationY += amount;
//  else if (direction == 1)
//    translationX += amount;
//  else if (direction == 2)
//    translationY -= amount;
//  else if (direction == 3)
//    translationX -= amount;
//  else if (direction == 4)
//    translationZ -= amount;
//  else if (direction == 5)
//    translationZ += amount;
//  update();
//}

//void OpenGLWidget::rotateModel(int direction, float amount) {
//  if (direction == 0)
//    rotationAngleY += amount;
//  else if (direction == 1)
//    rotationAngleX += amount;
//  else if (direction == 2)
//    rotationAngleY -= amount;
//  else if (direction == 3)
//    rotationAngleX -= amount;
//  else if (direction == 4)
//    rotationAngleZ -= amount;
//  else if (direction == 5)
//    rotationAngleZ += amount;
//  update();
//}

//void OpenGLWidget::ceterModel() {
//  translationZ = -m_medianZ * scaleBy;
//  translationX = -m_medianX * scaleBy;
//  translationY = -m_medianY * scaleBy;
//  update();
//}

//void OpenGLWidget::changePerspective() {
//  ortho = !ortho;

//  resizeGL(OpenGLWidget::width(), OpenGLWidget::height());
//}

//void OpenGLWidget::showVert() {
//  vertexesShown = !vertexesShown;
//  update();
//}

//void OpenGLWidget::disLines() {
//  linesShown = !linesShown;
//  update();
//}

//void OpenGLWidget::changeVertDisplay() {
//  smoothVertexes = !smoothVertexes;
//  update();
//}

//void OpenGLWidget::changeEdgeDisplay() {
//  lineStrip = !lineStrip;
//  update();
//}

void OpenGLWidget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) last_mouse_pos_ = event->pos();
  if (event->button() == Qt::RightButton) last_rmouse_pos_ = event->pos();
}

void OpenGLWidget::wheelEvent(QWheelEvent *event) {
  translation_z_ += static_cast<float>(event->angleDelta().y()) / 120.0f;
  update();
}

void OpenGLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(settings_.back_color.redF(), settings_.back_color.greenF(), settings_.back_color.blueF(),
               settings_.back_color.alphaF());
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
  glGenBuffers(1, &vertex_buffer_);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_.size(),
               vertex_.data(), GL_STATIC_DRAW);
  glGenBuffers(1, &index_buffer_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * face_.size(),
               face_.data(), GL_STATIC_DRAW); //вынести в метов
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
     projection_matrix_.perspective(60.0f, static_cast<float>(w) / (h), 0.1f, 100.0f);
  /*----------------------------------------------------------------------------------------------------------------------*/
}

void OpenGLWidget::paintGL() {
  /*----------------------------------------------------------------------------------------------------------------------*/
//  if (backgroundChanged) {
    glClearColor(settings_.back_color.redF(), settings_.back_color.greenF(),
                 settings_.back_color.blueF(), settings_.back_color.alphaF());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    backgroundChanged = false;
//  }
  shader_programm_.bind();
  shader_programm_.setUniformValue("dashed", false);
  shader_programm_.setUniformValue("projectionMatrix", projection_matrix_);
  model_view_matrix_.setToIdentity();
  model_view_matrix_.translate(translation_x_, translation_y_, -2.5 + translation_z_);
//  model_view_matrix_.scale(scale_);
//  if (lineThicknessChanged) {
//    glLineWidth(static_cast<float>(lineThickness));
//    lineThicknessChanged = false;
//  }
//  if (vertexThicknessChanged) {
//    glPointSize(50);
//    vertexThicknessChanged = false;
//  }
  model_view_matrix_.rotate(rotation_y_, 1.0, 0.0, 0.0f);
  model_view_matrix_.rotate(rotation_x_, 0.0, 1.0, 0.0f);
  model_view_matrix_.rotate(rotation_z_, 0.0, 0.0, 1.0f);
  shader_programm_.setUniformValue("modelViewMatrix", model_view_matrix_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);
//  settings_.smooth_vertexes ? glEnable(GL_POINT_SMOOTH) : glDisable(GL_POINT_SMOOTH);
//  if (vertexesShown) {
//    shader_programm_.setUniformValue("color", settings_.vertex_color);
//    glDrawElements(GL_POINTS, face_.size(), GL_UNSIGNED_INT, nullptr);
//    shader_programm_.setUniformValue("color", settings_.color);
//  }
//  lineStrip ? shaderProgram.setUniformValue("dashed", true)
//            : shaderProgram.setUniformValue("dashed", false);
//  if (linesShown)
  glDrawElements(GL_LINES, face_.size(), GL_UNSIGNED_INT, nullptr);
  shader_programm_.release();
  /*----------------------------------------------------------------------------------------------------------------------*/
}
