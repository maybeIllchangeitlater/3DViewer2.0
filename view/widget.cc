#include "widget.h"

#include <QResource>
#include <iostream>

OpenGLWidget::OpenGLWidget(s21::Settings &settings, s21::Controller &controller,
                           QWidget *parent)
    : settings_(settings),
      controller_(controller),
      QOpenGLWidget(parent),
      vbo_(QOpenGLBuffer::VertexBuffer),
      vbo_light_((QOpenGLBuffer::VertexBuffer)),
      ibo_(QOpenGLBuffer::IndexBuffer) {}

OpenGLWidget::~OpenGLWidget() {}

void OpenGLWidget::ChangeShaders() {
  shader_programm_.removeAllShaders();
  shader_version_.reset();
  AddShaders();
  shader_programm_.link();
  update();
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    QPoint delta = event->pos() - last_mouse_pos_;
    settings_.rotation[0] += delta.x();
    settings_.rotation[1] += delta.y();
    update();
    last_mouse_pos_ = event->pos();
  } else if (event->buttons() & Qt::RightButton) {
    QPoint delta = event->pos() - last_rmouse_pos_;
    settings_.translation[0] += delta.x() / 100.0f;
    settings_.translation[1] -= delta.y() / 100.0f;
    update();
    last_rmouse_pos_ = event->pos();
  }
}

void OpenGLWidget::AddShaders() {
    /////testing flat
    shader_programm_.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/resources/FragShaderNoGeometry.txt");
    shader_programm_.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/resources/VertexShaderFlat.txt");
}

void OpenGLWidget::ConfigureAttributeBuffers()
{
    int vertex_location = shader_programm_.attributeLocation("position");
    shader_programm_.enableAttributeArray(vertex_location);
    shader_programm_.setAttributeBuffer(vertex_location, GL_FLOAT, 0, s21::VERTEX_PROPERTIES_SIZE,
                                        sizeof(GLfloat) * controller_.GetObjectPropertiesCount());

    if(controller_.ObjectHasTextures()){
        has_texture_map_ = true;
        int texture_map_location = shader_programm_.attributeLocation("textures");
        shader_programm_.enableAttributeArray(texture_map_location);
        shader_programm_.setAttributeBuffer(texture_map_location, GL_FLOAT, sizeof(GLfloat) * s21::VERTEX_PROPERTIES_SIZE,
                                            s21::TEXTURE_PROPERTIES_SIZE,
                                           sizeof(GLfloat) * controller_.GetObjectPropertiesCount());
    }

    if(controller_.ObjectHasNormales()){
        has_normales_ = true;
        settings_.lights_on = true;
        settings_.wireframe = false;
        int normal_location = shader_programm_.attributeLocation("normal");
        shader_programm_.enableAttributeArray(normal_location);
        int normales_offset = has_texture_map_
                ? (s21::VERTEX_PROPERTIES_SIZE + s21::TEXTURE_PROPERTIES_SIZE) * sizeof(GLfloat)
                : s21::VERTEX_PROPERTIES_SIZE * sizeof(GLfloat);
        shader_programm_.setAttributeBuffer(normal_location, GL_FLOAT, normales_offset,
                                            s21::NORMALE_PROPERTIES_SIZE,
                                            sizeof(GLfloat) * controller_.GetObjectPropertiesCount());
    }
}

void OpenGLWidget::LightsOn()
{
    shader_light_.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/resources/LightFragShader.txt");
    shader_light_.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/resources/LightVertexShader.txt");
    shader_light_.link();
    shader_light_.bind();
    vao_light_.create();
    vbo_light_.create();

    GLfloat lamp_vertices[] = {
        1.000000,  1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000,
        -1.000000, 1.000000,  1.000000,  1.000000,  1.000000,  -1.000000,
        -1.000000, 1.000000,  1.000000,  1.000000,  1.000000,  1.000000,
        1.000000,  -1.000000, 1.000000,  1.000000,  1.000000,  1.000000,
        -1.000000, 1.000000,  1.000000,  1.000000,  -1.000000, 1.000000,
        -1.000000, 1.000000,  1.000000,  -1.000000, -1.000000, 1.000000,
        -1.000000, -1.000000, 1.000000,  -1.000000, 1.000000,  1.000000,
        -1.000000, 1.000000,  -1.000000, -1.000000, -1.000000, 1.000000,
        -1.000000, 1.000000,  -1.000000, -1.000000, -1.000000, -1.000000,
        -1.000000, -1.000000, -1.000000, 1.000000,  -1.000000, -1.000000,
        1.000000,  -1.000000, 1.000000,  -1.000000, -1.000000, -1.000000,
        1.000000,  -1.000000, 1.000000,  -1.000000, -1.000000, 1.000000,
        1.000000,  -1.000000, -1.000000, 1.000000,  1.000000,  -1.000000,
        1.000000,  1.000000,  1.000000,  1.000000,  -1.000000, -1.000000,
        1.000000,  1.000000,  1.000000,  1.000000,  -1.000000, 1.000000,
        -1.000000, -1.000000, -1.000000, -1.000000, 1.000000,  -1.000000,
        1.000000,  1.000000,  -1.000000, -1.000000, -1.000000, -1.000000,
        1.000000,  1.000000,  -1.000000, 1.000000,  -1.000000, -1.000000};

    vbo_light_.allocate(lamp_vertices, sizeof(GLfloat) * 36 * 3);
    vbo_light_.setUsagePattern(QOpenGLBuffer::StaticDraw);

    vao_light_.bind();
    vbo_light_.bind();

    shader_light_.setAttributeBuffer("lPosistion", GL_FLOAT, 0, 3);
    shader_light_.enableAttributeArray("lPosistion");
    shader_light_.bind();

    vao_light_.release();
    vbo_light_.release();
    shader_light_.release();
}

void OpenGLWidget::CalculateCamera()
{
    float sin_rot_x = std::sin(settings_.rotation[0] * M_PI / 180);
    float sin_rot_y = std::sin(settings_.rotation[1] * M_PI / 180);
    float cos_rot_x = std::cos(settings_.rotation[0] * M_PI / 180);
    float cos_rot_y = std::cos(settings_.rotation[1] * M_PI / 180);

    float radial_distance_from_origin = 3.0f * cos_rot_y;

      settings_.camera[0] = radial_distance_from_origin * sin_rot_x;
      settings_.camera[1] = 3.0f * sin_rot_y;
      settings_.camera[2] = radial_distance_from_origin * cos_rot_x;

      settings_.camera_up[0] = -sin_rot_x * sin_rot_y;
      settings_.camera_up[1] = cos_rot_y;
      settings_.camera_up[2] = -cos_rot_x * sin_rot_y;
}

void OpenGLWidget::ConfigureDisplay()
{
    if (texture_) {
        shader_programm_.setUniformValue("textured", true);
        texture_->bind();
      } else {
        shader_programm_.setUniformValue("textured", false);
        shader_programm_.setUniformValue("pointColor", settings_.vertex_color);
        shader_programm_.setUniformValue("lineColor", settings_.color);
      }
      if (has_normales_ && !settings_.wireframe && settings_.lights_on) {
            shader_programm_.setUniformValue("normales", true);
            shader_programm_.setUniformValue("lightColor", settings_.light_color);
            shader_programm_.setUniformValueArray("lightPosition", &settings_.light_position, 1);
            shader_programm_.setUniformValueArray("cameraPosition", &settings_.camera, 1);
            shader_programm_.setUniformValue("flat", settings_.flat_shading ? true : false);
            shader_programm_.setUniformValue("ambient", settings_.ambient);
            shader_programm_.setUniformValue("specular", settings_.specular);
      } else {
            shader_programm_.setUniformValue("normales", false);
            shader_programm_.setUniformValue("lineWidth", settings_.line_width);
            shader_programm_.setUniformValue("pointWidth", settings_.point_size);
            shader_programm_.setUniformValue("showVertex", settings_.vertexes_shown);
            shader_programm_.setUniformValue("smoothVertex", settings_.smooth_vertexes);
            shader_programm_.setUniformValue("showLines", settings_.lines_shown);
            shader_programm_.setUniformValue("edgedLines", settings_.broken_lines);
      }
}

void OpenGLWidget::DrawLight()
{

        if (has_normales_ && !settings_.wireframe && settings_.lights_on) {
          shader_light_.bind();
          vao_light_.bind();

          QMatrix4x4 lamp;

          shader_light_.setUniformValueArray("projectionMatrix", &projection_matrix_, 1);
          shader_light_.setUniformValueArray("modelMatrix", &model_view_matrix_, 1);


          lamp.translate(settings_.light_position);
          lamp.scale(0.1f);

          shader_light_.setUniformValueArray("model", &lamp, 1);


          glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
          glDrawArrays(GL_TRIANGLES, 0, 36);

          vao_light_.release();
          shader_light_.release();
        }

}

void OpenGLWidget::ChangePerspective() {
  resizeGL(OpenGLWidget::width(), OpenGLWidget::height());
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) last_mouse_pos_ = event->pos();
  if (event->button() == Qt::RightButton) last_rmouse_pos_ = event->pos();
}

void OpenGLWidget::wheelEvent(QWheelEvent *event) {
  settings_.translation[2] -=
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

  vbo_.create();
  vbo_.bind();
  vbo_.allocate(controller_.GetVertexDataConstRef().data(),
                controller_.GetVertexDataConstRef().size() * sizeof(GLfloat));
  vbo_.setUsagePattern(QOpenGLBuffer::StaticDraw);

  ibo_.create();
  ibo_.bind();
  ibo_.allocate(controller_.GetFaceConstRef().data(),
                controller_.GetFaceConstRef().size() * sizeof(GLuint));
  ibo_.setUsagePattern(QOpenGLBuffer::StaticDraw);

  vao_.create();
  vao_.bind();

  ConfigureAttributeBuffers();

  vbo_.release();
  vao_.release();
  ibo_.release();
  shader_programm_.release();

  LightsOn();
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
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  CalculateCamera();

  shader_programm_.bind();
  shader_programm_.setUniformValue("projectionMatrix", projection_matrix_);
  controller_.MoveModel(model_view_matrix_, settings_);
  shader_programm_.setUniformValue("modelViewMatrix", model_view_matrix_);
  ConfigureDisplay();
  model_view_matrix_.lookAt(settings_.camera, {0, 0, 0}, settings_.camera_up);

  vao_.bind();
  ibo_.bind();

  glDrawElements(GL_TRIANGLES, controller_.GetFaceConstRef().size(),
                 GL_UNSIGNED_INT, nullptr);

  ibo_.release();
  vao_.release();
  shader_programm_.release();

  DrawLight();
}
