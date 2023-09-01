#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "widget.h"
MainWindow::MainWindow(s21::Controller &controller, QWidget *parent)
    : controller_(controller),
      QMainWindow(parent),
      ui_(new Ui::MainWindow),
      gl_widget_(nullptr) {
  ui_->setupUi(this);
  ui_->scale_slider->setSliderPosition(settings_.scale * 100);
  ui_->line_thicc->setSliderPosition(settings_.line_width);
  ui_->vertex_thicc->setSliderPosition(settings_.point_size);
  connect(ui_->mDown, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui_->mUp, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui_->mLeft, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui_->mRight, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui_->mBackward, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui_->mForward, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui_->rDown, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui_->rUp, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui_->rLeft, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui_->rRight, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui_->rzUp, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui_->rzDown, SIGNAL(clicked()), this, SLOT(rotateBy()));

  connect(ui_->Browse, SIGNAL(clicked()), this, SLOT(BrowseModel()));
  connect(ui_->background_color, SIGNAL(clicked()), this,
          SLOT(ChangeBackgroundColor()));
  connect(ui_->line_color, SIGNAL(clicked()), this, SLOT(ChangeLineColor()));
  connect(ui_->vertex_color, SIGNAL(clicked()), this,
          SLOT(ChangeVertexColor()));
    ConnectToLambdas();

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
                         this);  // change to const reference, save in back
    //        ui_->line_thicc->setVisible(true);
    ui_->viewer_layout->addWidget(gl_widget_);
  } catch (std::exception e) {
    ui_->model_name->setText(e.what());
  }

  /*----------------------------------------------------------------------------------------------------------------------*/
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

//void MainWindow::RotateBy() {
//  if (gl_widget_) {
//    gl_widget_->RotateModel(
//        qobject_cast<QPushButton *>(sender())->text() == "↑"   ? 0
//        : qobject_cast<QPushButton *>(sender())->text() == "→" ? 1
//        : qobject_cast<QPushButton *>(sender())->text() == "↓" ? 2
//        : qobject_cast<QPushButton *>(sender())->text() == "←" ? 3
//        : qobject_cast<QPushButton *>(sender())->text() == "⇧" ? 4
//                                                               : 5,
//        ui_->translateBy->text().toFloat());
//  }
//}

void MainWindow::closeEvent(QCloseEvent *event) {
  settings_.SaveSettings();
  event->accept();
}

void MainWindow::ConnectToLambdas()
{
    ui_->line_thicc->connect(ui_->line_thicc, &QSlider::valueChanged,
                             [this](int w) {
                               settings_.line_width = w;
                               if (gl_widget_) gl_widget_->update();
                             });
    ui_->vertex_thicc->connect(ui_->vertex_thicc, &QSlider::valueChanged,
                               [this](int w) {
                                 settings_.point_size = w;
                                 if (gl_widget_) gl_widget_->update();
                               });
    ui_->scale_slider->connect(ui_->scale_slider, &QSlider::valueChanged,
                               [this](int w) {
                                 settings_.scale = static_cast<float>(w) / 100.0f;
                                 if (gl_widget_) gl_widget_->update();
                               });
    ui_->show_lines->connect(ui_->show_lines, &QCheckBox::toggled,
                             [this](bool b) {
                               settings_.lines_shown = b;
                               if (gl_widget_) gl_widget_->update();
                             });
    ui_->show_vertexes->connect(ui_->show_vertexes, &QCheckBox::toggled,
                                [this](bool b) {
                                  settings_.vertexes_shown = b;
                                  if (gl_widget_) gl_widget_->update();
                                });
    ui_->broken_lines->connect(ui_->broken_lines, &QCheckBox::toggled,
                               [this](bool b) {
                                 settings_.broken_lines = b;
                                 if (gl_widget_) gl_widget_->update();
                               });
    ui_->smooth_vertexes->connect(ui_->smooth_vertexes, &QCheckBox::toggled,
                                  [this](bool b) {
                                    settings_.smooth_vertexes = b;
                                    if (gl_widget_) gl_widget_->update();
                                  });
}
