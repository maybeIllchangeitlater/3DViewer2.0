#include "mainwindow.h"

#include "ui_mainwindow.h"
MainWindow::MainWindow(s21::Controller &controller, QWidget *parent)
    : controller_(controller), QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  ui->ScaleSlider->setEnabled(false);
  ui->line_thicc->setVisible(false);
  ui->line_thicc->setEnabled(false);
  ui->vertex_thicc->setVisible(false);
  ui->vertex_thicc->setEnabled(false);
  ui->close_vertex_wid->setVisible(false);
  ui->close_vertex_wid->setEnabled(false);
  ui->close_line_wid->setVisible(false);
  ui->close_line_wid->setEnabled(false);

  connect(ui->mDown, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui->mUp, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui->mLeft, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui->mRight, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui->mBackward, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui->mForward, SIGNAL(clicked()), this, SLOT(translateBy()));
  connect(ui->rDown, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui->rUp, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui->rLeft, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui->rRight, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui->rzUp, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui->rzDown, SIGNAL(clicked()), this, SLOT(rotateBy()));
  connect(ui->showLines, SIGNAL(clicked()), this, SLOT(displayLines()));
  connect(ui->vertex_t, SIGNAL(clicked()), this, SLOT(on_vertex_t_clicked()));
  connect(ui->close_vertex_wid, SIGNAL(clicked()), this,
          SLOT(vertex_wid_clicked()));  // here
  connect(ui->color, SIGNAL(clicked), this, SLOT(OnColorClicked()));
  connect(ui->color_2, SIGNAL(clicked), this, SLOT(OnColorClicked()));
  connect(ui->color_3, SIGNAL(clicked), this, SLOT(OnColorClicked()));
}

MainWindow::~MainWindow() { delete ui; if(gl_widget_) delete gl_widget_; }

void MainWindow::on_Browse_clicked() {
  QString filename(QFileDialog::getOpenFileName(
        this, "Open File", static_cast<QDir>(QDir::homePath()).absolutePath() + "/Desktop/viewer/models/",
        "obj files (*.obj)"));
  bool opened = controller_.OpenFile(filename);
  /*----------------------------------------------------------------------------------------------------------------------*/
  if (gl_widget_) {
    ui->ViewerLayout->removeWidget(gl_widget_);
    ui->model_name->setText("");
    delete gl_widget_;
  }
  if(opened)
      gl_widget_ = controller_.Display_Model();
       ui->ViewerLayout->addWidget(gl_widget_);
       ui->model_name->setText(filename);
}
//вынести этот кал в отдельный метод
//void MainWindow::closeEvent(QCloseEvent *event) {
//  settings_.SaveSettings();
//  event->accept();
//}

//ПЕРЕДЕЛАТЬ ЭТОТ КАЛ И ВСЕ ЧТО ВНУТРИ
//void MainWindow::OpenAndParseFile() {


//  if (!filename.isEmpty()) {
//    ui->ScaleSlider->setSliderPosition(100);
//    ui->ScaleSlider->setEnabled(true);
//    std::string filee = filename.toStdString();
//    const char *file = filee.data();
//    parseObjFile(file, &bigstructarray);
//    if (!indices.empty()) {
//      indices.clear();
//      vertexPositions.clear();
//    }
//  }
//}


//void MainWindow::on_ScaleSlider_sliderMoved(int position) {
//  if (glWidget) {
//    glWidget->scaleModel(position);
//  }
//}

//void MainWindow::on_line_thicc_sliderMoved(int position) {
//  lineW = position;
//  if (glWidget) glWidget->scaleLines(position);
//}

//void MainWindow::on_vertex_thicc_sliderMoved(int position) {
//  vertexW = position;
//  if (glWidget) glWidget->scaleVertex(position);
//}

//void MainWindow::OnColorClicked()
//{
//    QColorDialog color_dialog(this);
//    QColor tmp(color_dialog.getColor(Qt::white, this));

//    if(qobject_cast<QPushButton*>(sender())->objectName() == "color")
//      settings_.color = tmp.isValid() ? std::move(tmp) : QColorConstants::White;
//    else if(qobject_cast<QPushButton*>(sender())->objectName() == "color_1")
//      settings_.back_color = tmp.isValid() ? std::move(tmp) : QColorConstants::Black;
//    else
//       settings_.vertex_color = tmp.isValid() ? std::move(tmp) : QColorConstants::Red; //change to map?,
//      //////DONT FORGET TO UPDATE GLWIDGET
//}

//void MainWindow::on_line_t_clicked() {
//  ui->line_thicc->setVisible(true);
//  ui->line_thicc->setEnabled(true);
//  ui->close_line_wid->setVisible(true);
//  ui->close_line_wid->setEnabled(true);
//}

//void MainWindow::on_vertex_t_clicked() {
//  ui->vertex_thicc->setVisible(true);
//  ui->vertex_thicc->setEnabled(true);
//  ui->close_vertex_wid->setVisible(true);
//  ui->close_vertex_wid->setEnabled(true);
//}

//void MainWindow::vertex_wid_clicked() {
//  ui->vertex_thicc->setVisible(false);
//  ui->vertex_thicc->setEnabled(false);
//  ui->close_vertex_wid->setVisible(false);
//  ui->close_vertex_wid->setEnabled(false);
//}

//void MainWindow::on_close_line_wid_clicked() {
//  ui->line_thicc->setVisible(false);
//  ui->line_thicc->setEnabled(false);
//  ui->close_line_wid->setVisible(false);
//  ui->close_line_wid->setEnabled(false);
//}

//void MainWindow::translateBy() {
//  if (glWidget) {
//    glWidget->translateModel(
//        qobject_cast<QPushButton *>(sender())->text() == "↑"   ? 0
//        : qobject_cast<QPushButton *>(sender())->text() == "→" ? 1
//        : qobject_cast<QPushButton *>(sender())->text() == "↓" ? 2
//        : qobject_cast<QPushButton *>(sender())->text() == "←" ? 3
//        : qobject_cast<QPushButton *>(sender())->text() == "⇧" ? 4
//                                                               : 5,
//        ui->translateBy->text().toFloat());
//  }
//}

//void MainWindow::rotateBy() {
//  if (glWidget) {
//    glWidget->rotateModel(
//        qobject_cast<QPushButton *>(sender())->text() == "⇡"   ? 0
//        : qobject_cast<QPushButton *>(sender())->text() == "⇢" ? 1
//        : qobject_cast<QPushButton *>(sender())->text() == "⇣" ? 2
//        : qobject_cast<QPushButton *>(sender())->text() == "⇢" ? 3
//        : qobject_cast<QPushButton *>(sender())->text() == "↖" ? 4
//                                                               : 5,
//        ui->rotateBy->text().toFloat());
//  }
//}

//void MainWindow::on_centerModel_clicked() {
//  if (glWidget) {
//    glWidget->ceterModel();
//  }
//}

//void MainWindow::on_gif_clicked() {
//  if (glWidget) {
//    imagecounter = 0;
//    connect(&timer, SIGNAL(timeout()), this, SLOT(makeScreenshot()));
//    timer.start(100);
//  }
//}

//void MainWindow::on_takeJpeg_clicked() {
//  if (glWidget) {
//    imagecounter = -1;
//    makeScreenshot();
//  }
//}

//void MainWindow::on_takeBmp_clicked() {
//  if (glWidget) {
//    imagecounter = -2;
//    makeScreenshot();
//  }
//}

//void MainWindow::on_changePerspective_clicked() {
//  if (glWidget) {
//    glWidget->changePerspective();
//  }
//  orth_ = !orth_;
//}

//void MainWindow::makeScreenshot() {
//  QPixmap pixmap = glWidget->grab();
//  QImage image = pixmap.toImage();
//  jiff.append(
//      image.scaled(640, 480, Qt::KeepAspectRatio, Qt::SmoothTransformation));
//  imagecounter++;
//  if (imagecounter >= 50) {
//    timer.stop();
//    makeVidya();
//  } else if (imagecounter == 0 || imagecounter == -1) {
//    image.save(dir.absolutePath() + "/Desktop/viewer/screenshot_" +
//               QString::number(screenshotcounter++) +
//               (imagecounter == 0 ? ".jpeg" : ".bmp"));
//    imagecounter = 0;
//  }
//}

//void MainWindow::makeVidya() {
//  QGifImage *gifim = new QGifImage();
//  gifim->setDefaultDelay(100);
//  for (const QImage &img : jiff) {
//    gifim->addFrame(img);
//  }
//  gifim->save(dir.absolutePath() + "/Desktop/viewer/output.gif");
//  delete gifim;
//  imagecounter = 0;
//  jiff.clear();
//}

//void MainWindow::on_showVertexes_clicked() {
//  if (glWidget) glWidget->showVert();
//  vertexes_shown_ = !vertexes_shown_;
//}

//void MainWindow::on_showVertexes_2_clicked() {
//  if (glWidget) glWidget->changeVertDisplay();
//  smoothVertexes = !smoothVertexes;
//}

//void MainWindow::on_brokenLines_clicked() {
//  if (glWidget) glWidget->changeEdgeDisplay();
//  brokenEdges = !brokenEdges;
//}

//void MainWindow::displayLines() {
//  if (glWidget) glWidget->disLines();
//  showLines = !showLines;
//}
