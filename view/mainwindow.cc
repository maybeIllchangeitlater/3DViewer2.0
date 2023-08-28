#include "mainwindow.h"
#include <tuple>
#include "ui_mainwindow.h"
#include "widget.h"
MainWindow::MainWindow(s21::Controller &controller, QWidget *parent)
    : controller_(controller), QMainWindow(parent), ui_(new Ui::MainWindow), gl_widget_(nullptr) {
  ui_->setupUi(this);
  ui_->ScaleSlider->setEnabled(false);
  ui_->line_thicc->setVisible(false);
  ui_->line_thicc->setEnabled(false);
  ui_->vertex_thicc->setVisible(false);
  ui_->vertex_thicc->setEnabled(false);
  ui_->close_vertex_wid->setVisible(false);
  ui_->close_vertex_wid->setEnabled(false);
  ui_->close_line_wid->setVisible(false);
  ui_->close_line_wid->setEnabled(false);
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
  connect(ui_->showLines, SIGNAL(clicked()), this, SLOT(displayLines()));
  connect(ui_->vertex_t, SIGNAL(clicked()), this, SLOT(on_vertex_t_clicked()));
  connect(ui_->close_vertex_wid, SIGNAL(clicked()), this,
          SLOT(vertex_wid_clicked()));  // here

  connect(ui_->Browse, SIGNAL(clicked()), this, SLOT(BrowseModelWraper()));
}

MainWindow::~MainWindow() {
    std::cout << "destructor destroy" << std::endl;
    if(gl_widget_) {delete gl_widget_;}
    delete ui_;
}
//template<typename ...Types>
void MainWindow::BrowseModel() {
    QString filename(QFileDialog::getOpenFileName(
          this, "Open File", static_cast<QDir>(QDir::homePath()).absolutePath() + "/Desktop/viewer/models/",
          "obj files (*.obj)"));
    try{
        controller_.OpenFile(filename);
        if(gl_widget_){
           ui_->viewer_layout->removeWidget(gl_widget_);
           delete gl_widget_;
        }
        ui_->model_name->setText(filename);
        gl_widget_ = new OpenGLWidget(controller_.GetVertexConstRef(), controller_.GetFaceConstRef(), this); //change to const reference, save in back
        ui_->viewer_layout->addWidget(gl_widget_);
    }catch(std::exception e){
        ui_->model_name->setText(e.what());
    }

  /*----------------------------------------------------------------------------------------------------------------------*/

}

//void MainWindow::closeEvent(QCloseEvent *event) {
//  gl+saveSettings();
//  event->accept();
//}



void MainWindow::BrowseModelWraper()
{
    BrowseModel();
}
