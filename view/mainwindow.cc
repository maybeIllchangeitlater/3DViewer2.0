#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "widget.h"
#include <QSurface>

MainWindow::MainWindow(s21::Controller &controller, QWidget *parent)
    : controller_(controller),
      QMainWindow(parent),
      ui_(new Ui::MainWindow),
      gl_widget_(nullptr) {
    QSurfaceFormat window_surface = QSurfaceFormat::defaultFormat();
        window_surface.setMajorVersion(3);
        window_surface.setMinorVersion(3);
        window_surface.setProfile(QSurfaceFormat::CoreProfile);
        QSurfaceFormat::setDefaultFormat(window_surface);
  ui_->setupUi(this);
  ui_->scale_slider->setSliderPosition(settings_.scale * 100);
  ui_->line_thicc->setSliderPosition(settings_.line_width);
  ui_->vertex_thicc->setSliderPosition(settings_.point_size);

  connect(ui_->Browse, SIGNAL(clicked()), this, SLOT(BrowseModel()));
  connect(ui_->background_color, SIGNAL(clicked()), this,
          SLOT(ChangeBackgroundColor()));
  connect(ui_->line_color, SIGNAL(clicked()), this, SLOT(ChangeLineColor()));
  connect(ui_->vertex_color, SIGNAL(clicked()), this,
          SLOT(ChangeVertexColor()));
    ConnectToLambdas();
    ConnectTranslateToLambdas();
    ConnectRotateToLambdas();

}

MainWindow::~MainWindow() {
  std::cout << "destructor destroy" << std::endl;
  if (gl_widget_) {
    delete gl_widget_;
  }
  delete ui_;
}
void MainWindow::BrowseModel() {
  QString filename(QFileDialog::getOpenFileName(
      this, "Open File",
      static_cast<QDir>(QDir::homePath()).absolutePath() +
          "/Desktop/viewer/models/",
      "obj files (*.obj)"));
  try {
    controller_.ParseFile(filename);
    if (gl_widget_) {
      ui_->viewer_layout->removeWidget(gl_widget_);
      delete gl_widget_;
    }
    ui_->model_name->setText(filename);
    gl_widget_ =
        new OpenGLWidget(settings_, controller_,
                         this);
    ui_->viewer_layout->addWidget(gl_widget_);
  } catch (std::exception e) {
    ui_->model_name->setText(e.what());
  }
}

void MainWindow::ChangeBackgroundColor() {
  QColorDialog colorDialog(this);
  settings_.back_color = colorDialog.getColor(Qt::white, this);
  if (!settings_.back_color.isValid())
    settings_.back_color = QColorConstants::Black;
  if (gl_widget_) gl_widget_->update();
}

void MainWindow::ChangeLineColor() {
  QColorDialog colorDialog(this);
  settings_.color = colorDialog.getColor(Qt::white, this);
  if (!settings_.color.isValid()) settings_.color = QColorConstants::White;
  if (gl_widget_) gl_widget_->update();
}

void MainWindow::ChangeVertexColor() {
  QColorDialog colorDialog(this);
  settings_.vertex_color = colorDialog.getColor(Qt::white, this);
  if (!settings_.vertex_color.isValid())
    settings_.vertex_color = QColorConstants::Red;
  if (gl_widget_) gl_widget_->update();
}


void MainWindow::closeEvent(QCloseEvent *event) {
  settings_.SaveSettings();
  event->accept();
}


void MainWindow::ConnectToLambdas()
{
    ui_->line_thicc->connect(ui_->line_thicc, &QSlider::valueChanged, this,
                             [this](int w) {
                               settings_.line_width = w;
                               UpdateWidget();
                             });
    ui_->vertex_thicc->connect(ui_->vertex_thicc, &QSlider::valueChanged, this,
                               [this](int w) {
                                 settings_.point_size = w;
                                 UpdateWidget();
                               });
    ui_->scale_slider->connect(ui_->scale_slider, &QSlider::valueChanged, this,
                               [this](int w) {
                                 settings_.scale = static_cast<float>(w) / 100.0f;
                                 UpdateWidget();
                               });
    ui_->show_lines->connect(ui_->show_lines, &QCheckBox::toggled, this,
                             [this](bool b) {
                               settings_.lines_shown = b;
                               UpdateWidget();
                             });
    ui_->show_vertexes->connect(ui_->show_vertexes, &QCheckBox::toggled, this,
                                [this](bool b) {
                                  settings_.vertexes_shown = b;
                                  UpdateWidget();
                                });
    ui_->broken_lines->connect(ui_->broken_lines, &QCheckBox::toggled, this,
                               [this](bool b) {
                                 settings_.broken_lines = b;
                                 UpdateWidget();
                               });
    ui_->smooth_vertexes->connect(ui_->smooth_vertexes, &QCheckBox::toggled, this,
                                  [this](bool b) {
                                    settings_.smooth_vertexes = b;
                                    UpdateWidget();
    });
}

void MainWindow::ConnectTranslateToLambdas()
{
    ui_->mDown->connect(ui_->mDown, &QPushButton::clicked, this, [this](bool){
           settings_.translation_y -= ui_->translateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->mUp->connect(ui_->mUp, &QPushButton::clicked, this, [this](bool){
           settings_.translation_y += ui_->translateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->mLeft->connect(ui_->mLeft, &QPushButton::clicked, this, [this](bool){
           settings_.translation_x -= ui_->translateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->mRight->connect(ui_->mRight, &QPushButton::clicked, this, [this](bool){
           settings_.translation_x += ui_->translateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->mForward->connect(ui_->mForward, &QPushButton::clicked, this, [this](bool){
           settings_.translation_z -= ui_->translateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->mBackward->connect(ui_->mBackward, &QPushButton::clicked, this, [this](bool){
           settings_.translation_z += ui_->translateBy->text().toFloat();
           UpdateWidget();
    });
}

void MainWindow::ConnectRotateToLambdas()
{
    ui_->rDown->connect(ui_->rDown, &QPushButton::clicked, this, [this](bool){
           settings_.rotation_y += ui_->rotateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->rUp->connect(ui_->rUp, &QPushButton::clicked, this, [this](bool){
           settings_.rotation_y -= ui_->rotateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->rLeft->connect(ui_->rLeft, &QPushButton::clicked, this, [this](bool){
           settings_.rotation_x -= ui_->rotateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->rRight->connect(ui_->rRight, &QPushButton::clicked, this, [this](bool){
           settings_.rotation_x += ui_->rotateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->rzDown->connect(ui_->rzDown, &QPushButton::clicked, this, [this](bool){
           settings_.rotation_z += ui_->rotateBy->text().toFloat();
           UpdateWidget();
    });
    ui_->rzUp->connect(ui_->rzUp, &QPushButton::clicked, this, [this](bool){
           settings_.rotation_z -= ui_->rotateBy->text().toFloat();
           UpdateWidget();
    });
}

void MainWindow::UpdateWidget()
{
    if (gl_widget_) gl_widget_->update();
}
//TODO Move connects to separate class ?
