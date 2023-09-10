#include "mainwindow.h"

#include <QOffscreenSurface>
#include <QOpenGLFramebufferObject>
#include <iostream>

#include "ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller &controller, QWidget *parent)
    : controller_(controller),
      QMainWindow(parent),
      ui_(new Ui::MainWindow),
      enable_uncustomizable_lines_("Non-customizable, lines only(very fast)",
                                   this),
      enable_lines_("Customizable, lines only(fast)", this),
      enable_points_("Customizable, points only(slow)", this),
      enable_everything_("Customizable, everything(very slow)", this),
      shader_menu_(this),
      gl_widget_(nullptr) {
  CreateOpenGLContext();
  ui_->setupUi(this);
  SetShaderMenu();
  connect(ui_->Browse, SIGNAL(clicked()), this, SLOT(BrowseModel()));
  connect(ui_->background_color, SIGNAL(clicked()), this,
          SLOT(ChangeBackgroundColor()));
  connect(ui_->line_color, SIGNAL(clicked()), this, SLOT(ChangeLineColor()));
  connect(ui_->vertex_color, SIGNAL(clicked()), this,
          SLOT(ChangeVertexColor()));
  ConnectToLambdas();
  ConnectTranslateToLambdas();
  ConnectRotateToLambdas();
  LoadStyle();
  SetSliders();
  QObject::connect(&controller_, SIGNAL(ParseOver(bool)), this,
                   SLOT(UpdateView(bool)));
}

MainWindow::~MainWindow() {
  if (gl_widget_) {
    delete gl_widget_;
  }
  delete ui_;
}

void MainWindow::LoadStyle() {
  QFontDatabase::addApplicationFont(":/style/fonts/Tahoma.ttf");
  QFont font("Tahoma", 14);

  QFile style_file(":/style/style/style.ss");
  style_file.open(QIODevice::ReadOnly);

  QTextStream style_stream(&style_file);
  setStyleSheet(style_stream.readAll());
}

void MainWindow::BrowseModel() {
  QString filename(QFileDialog::getOpenFileName(
      this, "Open File",
      static_cast<QDir>(QDir::homePath()).absolutePath() +
          "/Desktop/viewer/models/",
      "obj files (*.obj)"));
  ui_->Browse->setEnabled(false);
  controller_.ParseFile(filename);
  ui_->model_name->setText("Loading...");
}

void MainWindow::UpdateView(bool correct_file) {
  if (gl_widget_) {
    ui_->viewer_layout->removeWidget(gl_widget_);
    delete gl_widget_;
    gl_widget_ = nullptr;
  }
  if (correct_file) {
    gl_widget_ = new OpenGLWidget(settings_, controller_, this);
    ui_->viewer_layout->addWidget(gl_widget_);
    ui_->model_name->setText(controller_.GetFilename());
  } else
    ui_->model_name->setText("Not this time");
  ui_->Browse->setEnabled(true);
}

void MainWindow::ChangeBackgroundColor() {
  QColorDialog colorDialog(this);
  settings_.back_color = colorDialog.getColor(Qt::white, this);
  if (!settings_.back_color.isValid())
    settings_.back_color = QColorConstants::Black;
  UpdateWidget();
}

void MainWindow::ChangeLineColor() {
  QColorDialog colorDialog(this);
  settings_.color = colorDialog.getColor(Qt::white, this);
  if (!settings_.color.isValid()) settings_.color = QColorConstants::White;
  UpdateWidget();
}

void MainWindow::ChangeVertexColor() {
  QColorDialog colorDialog(this);
  settings_.vertex_color = colorDialog.getColor(Qt::white, this);
  if (!settings_.vertex_color.isValid())
    settings_.vertex_color = QColorConstants::Red;
  UpdateWidget();
}

void MainWindow::closeEvent(QCloseEvent *event) {
  settings_.SaveSettings();
  event->accept();
}

void MainWindow::ConnectToLambdas() {
  connect(ui_->line_thicc, &QSlider::valueChanged, this, [this](int w) {
    settings_.line_width = static_cast<float>(w) / 100.0f;
    UpdateWidget();
  });
  connect(ui_->vertex_thicc, &QSlider::valueChanged, this, [this](int w) {
    settings_.point_size = static_cast<float>(w) / 100.0f;
    UpdateWidget();
  });
  connect(ui_->scale_slider, &QSlider::valueChanged, this, [this](int w) {
    settings_.scale = static_cast<float>(w) / 100.0f;
    UpdateWidget();
  });
  connect(ui_->show_lines, &QCheckBox::toggled, this, [this](bool b) {
    settings_.lines_shown = b;
    UpdateWidget();
  });
  connect(ui_->show_vertexes, &QCheckBox::toggled, this, [this](bool b) {
    settings_.vertexes_shown = b;
    UpdateWidget();
  });
  connect(ui_->broken_lines, &QCheckBox::toggled, this, [this](bool b) {
    settings_.broken_lines = b;
    UpdateWidget();
  });
  connect(ui_->smooth_vertexes, &QCheckBox::toggled, this, [this](bool b) {
    settings_.smooth_vertexes = b;
    UpdateWidget();
  });
  connect(ui_->takeBmp, &QPushButton::clicked, this, [this](bool) {
    if (gl_widget_) {
      MakeScreenshot(kBMP);
    }
  });
  connect(ui_->takeJpeg, &QPushButton::clicked, this, [this](bool) {
    if (gl_widget_) {
      MakeScreenshot(kJpeg);
    }
  });
  connect(ui_->gif, &QPushButton::clicked, this, [this](bool) {
    if (gl_widget_) {
      ui_->gif->setEnabled(false);
      MakeGif();
    }
  });
  connect(ui_->changePerspective, &QPushButton::clicked, this, [this](bool) {
    settings_.orth = !settings_.orth;  // сказать Снежанне переделать в галочку
    if (gl_widget_) {
      gl_widget_->ChangePerspective();
      gl_widget_->update();
    }
  });
}

void MainWindow::ConnectTranslateToLambdas() {
  connect(ui_->mDown, &QPushButton::clicked, this, [this](bool) {
    settings_.translation_y -= ui_->translateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->mUp, &QPushButton::clicked, this, [this](bool) {
    settings_.translation_y += ui_->translateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->mLeft, &QPushButton::clicked, this, [this](bool) {
    settings_.translation_x -= ui_->translateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->mRight, &QPushButton::clicked, this, [this](bool) {
    settings_.translation_x += ui_->translateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->mForward, &QPushButton::clicked, this, [this](bool) {
    settings_.translation_z -= ui_->translateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->mBackward, &QPushButton::clicked, this, [this](bool) {
    settings_.translation_z += ui_->translateBy->text().toFloat();
    UpdateWidget();
  });
}

void MainWindow::ConnectRotateToLambdas() {
  connect(ui_->rDown, &QPushButton::clicked, this, [this](bool) {
    settings_.rotation_y += ui_->rotateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->rUp, &QPushButton::clicked, this, [this](bool) {
    settings_.rotation_y -= ui_->rotateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->rLeft, &QPushButton::clicked, this, [this](bool) {
    settings_.rotation_x -= ui_->rotateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->rRight, &QPushButton::clicked, this, [this](bool) {
    settings_.rotation_x += ui_->rotateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->rzDown, &QPushButton::clicked, this, [this](bool) {
    settings_.rotation_z += ui_->rotateBy->text().toFloat();
    UpdateWidget();
  });
  connect(ui_->rzUp, &QPushButton::clicked, this, [this](bool) {
    settings_.rotation_z -= ui_->rotateBy->text().toFloat();
    UpdateWidget();
  });
}

void MainWindow::UpdateWidget() {
  if (gl_widget_) gl_widget_->update();
}

void MainWindow::SetSliders() noexcept {
  ui_->scale_slider->setSliderPosition(settings_.scale * 100);
  ui_->line_thicc->setSliderPosition(settings_.line_width * 100);
  ui_->vertex_thicc->setSliderPosition(settings_.point_size * 100);
  ui_->show_vertexes->setChecked(settings_.vertexes_shown);
  ui_->show_lines->setChecked(settings_.lines_shown);
  ui_->smooth_vertexes->setChecked(settings_.smooth_vertexes);
  ui_->broken_lines->setChecked(settings_.broken_lines);
}

void MainWindow::SetShaderMenu() {
  connect(&enable_uncustomizable_lines_, &QAction::triggered, this, [this]() {
    settings_.shader_version = s21::ShaderFactory::kLinesOnly;
    if (gl_widget_) gl_widget_->ChangeShaders();
  });
  connect(&enable_lines_, &QAction::triggered, this, [this]() {
    settings_.shader_version = s21::ShaderFactory::kCustomizableLines;
    if (gl_widget_) gl_widget_->ChangeShaders();
  });
  connect(&enable_points_, &QAction::triggered, this, [this]() {
    settings_.shader_version = s21::ShaderFactory::kPointsOnly;
    if (gl_widget_) gl_widget_->ChangeShaders();
  });
  connect(&enable_everything_, &QAction::triggered, this, [this]() {
    settings_.shader_version = s21::ShaderFactory::kEverything;
    if (gl_widget_) gl_widget_->ChangeShaders();
  });
  shader_menu_.addAction(&enable_uncustomizable_lines_);
  shader_menu_.addAction(&enable_lines_);
  shader_menu_.addAction(&enable_points_);
  shader_menu_.addAction(&enable_everything_);
  connect(ui_->changeShader, &QPushButton::clicked, this,
          [this]() { shader_menu_.exec(QCursor::pos()); });
}

void MainWindow::MakeScreenshot(enum ScreenShotMode mode) {
  QDir dir = QDir::homePath();
  gl_widget_->grab().toImage().save(dir.absolutePath() +
                                    "/Desktop/viewer/screenshot_" +
                                    QString::number(screenshotcounter_++) +
                                    (mode == kJpeg ? ".jpeg" : ".bmp"));
}

void MainWindow::MakeGif() {
  connect(&timer_, &QTimer::timeout, this, [&, this]() {
    if (image_.size() >= 50) {
      timer_.stop();
      std::thread t2([this]() { CompileAndSaveGif(); });
      t2.detach();
    } else
      image_.push_back(gl_widget_->grab().toImage().scaled(
          640, 480, Qt::KeepAspectRatio, Qt::SmoothTransformation));
  });
  timer_.start(100);
}

void MainWindow::CompileAndSaveGif() {
  QGifImage jiff;
  jiff.setDefaultDelay(100);
  QDir dir = QDir::homePath();
  for (const auto &v : image_) jiff.addFrame(v);
  jiff.save(dir.absolutePath() + "/Desktop/viewer/output.gif");
  image_.clear();
  ui_->gif->setEnabled(true);
}

void MainWindow::CreateOpenGLContext() {
  QSurfaceFormat window_surface = QSurfaceFormat::defaultFormat();
  window_surface.setMajorVersion(3);
  window_surface.setMinorVersion(3);
  window_surface.setProfile(QSurfaceFormat::CoreProfile);
  QSurfaceFormat::setDefaultFormat(window_surface);
}
