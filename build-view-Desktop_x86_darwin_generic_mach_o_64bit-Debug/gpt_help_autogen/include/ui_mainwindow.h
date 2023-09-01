/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *viewer_layout;
    QPushButton *Browse;
    QLabel *model_name;
    QPushButton *line_color;
    QPushButton *background_color;
    QSlider *scale_slider;
    QPushButton *rRight;
    QPushButton *rDown;
    QPushButton *rUp;
    QPushButton *rLeft;
    QPushButton *gif;
    QPushButton *changePerspective;
    QPushButton *centerModel;
    QPushButton *vertex_color;
    QPushButton *takeJpeg;
    QPushButton *takeBmp;
    QLineEdit *translateBy;
    QLineEdit *rotateBy;
    QPushButton *rzDown;
    QPushButton *rzUp;
    QCheckBox *show_vertexes;
    QCheckBox *broken_lines;
    QCheckBox *show_lines;
    QLabel *label;
    QLabel *label_2;
    QSlider *line_thicc;
    QSlider *vertex_thicc;
    QCheckBox *smooth_vertexes;
    QWidget *gridLayoutWidget;
    QGridLayout *move_layout;
    QPushButton *mRight;
    QPushButton *mDown;
    QPushButton *mUp;
    QPushButton *mForward;
    QPushButton *mLeft;
    QPushButton *mBackward;
    QLabel *label_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1392, 916);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 50, 621, 511));
        viewer_layout = new QVBoxLayout(verticalLayoutWidget);
        viewer_layout->setObjectName(QString::fromUtf8("viewer_layout"));
        viewer_layout->setSizeConstraint(QLayout::SetNoConstraint);
        viewer_layout->setContentsMargins(0, 0, 0, 0);
        Browse = new QPushButton(centralwidget);
        Browse->setObjectName(QString::fromUtf8("Browse"));
        Browse->setGeometry(QRect(640, 10, 131, 51));
        QFont font1;
        font1.setPointSize(26);
        font1.setBold(false);
        Browse->setFont(font1);
        model_name = new QLabel(centralwidget);
        model_name->setObjectName(QString::fromUtf8("model_name"));
        model_name->setGeometry(QRect(10, 0, 621, 41));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        model_name->setFont(font2);
        line_color = new QPushButton(centralwidget);
        line_color->setObjectName(QString::fromUtf8("line_color"));
        line_color->setGeometry(QRect(640, 60, 131, 51));
        line_color->setFont(font1);
        background_color = new QPushButton(centralwidget);
        background_color->setObjectName(QString::fromUtf8("background_color"));
        background_color->setGeometry(QRect(640, 110, 131, 51));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        background_color->setFont(font3);
        scale_slider = new QSlider(centralwidget);
        scale_slider->setObjectName(QString::fromUtf8("scale_slider"));
        scale_slider->setGeometry(QRect(10, 570, 621, 25));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setKerning(true);
        scale_slider->setFont(font4);
        scale_slider->setMaximum(200);
        scale_slider->setSliderPosition(100);
        scale_slider->setOrientation(Qt::Horizontal);
        rRight = new QPushButton(centralwidget);
        rRight->setObjectName(QString::fromUtf8("rRight"));
        rRight->setGeometry(QRect(1090, 410, 41, 31));
        rDown = new QPushButton(centralwidget);
        rDown->setObjectName(QString::fromUtf8("rDown"));
        rDown->setGeometry(QRect(1060, 430, 31, 41));
        rUp = new QPushButton(centralwidget);
        rUp->setObjectName(QString::fromUtf8("rUp"));
        rUp->setGeometry(QRect(1060, 380, 31, 41));
        rLeft = new QPushButton(centralwidget);
        rLeft->setObjectName(QString::fromUtf8("rLeft"));
        rLeft->setGeometry(QRect(1020, 410, 41, 31));
        gif = new QPushButton(centralwidget);
        gif->setObjectName(QString::fromUtf8("gif"));
        gif->setGeometry(QRect(1010, 470, 131, 51));
        gif->setFont(font1);
        changePerspective = new QPushButton(centralwidget);
        changePerspective->setObjectName(QString::fromUtf8("changePerspective"));
        changePerspective->setGeometry(QRect(1160, 260, 131, 51));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        changePerspective->setFont(font5);
        centerModel = new QPushButton(centralwidget);
        centerModel->setObjectName(QString::fromUtf8("centerModel"));
        centerModel->setGeometry(QRect(1010, 520, 131, 51));
        QFont font6;
        font6.setPointSize(20);
        font6.setBold(false);
        centerModel->setFont(font6);
        vertex_color = new QPushButton(centralwidget);
        vertex_color->setObjectName(QString::fromUtf8("vertex_color"));
        vertex_color->setGeometry(QRect(640, 160, 131, 51));
        QFont font7;
        font7.setPointSize(16);
        font7.setBold(false);
        vertex_color->setFont(font7);
        takeJpeg = new QPushButton(centralwidget);
        takeJpeg->setObjectName(QString::fromUtf8("takeJpeg"));
        takeJpeg->setGeometry(QRect(1150, 470, 131, 51));
        takeJpeg->setFont(font7);
        takeBmp = new QPushButton(centralwidget);
        takeBmp->setObjectName(QString::fromUtf8("takeBmp"));
        takeBmp->setGeometry(QRect(1150, 520, 131, 51));
        takeBmp->setFont(font7);
        translateBy = new QLineEdit(centralwidget);
        translateBy->setObjectName(QString::fromUtf8("translateBy"));
        translateBy->setGeometry(QRect(1150, 310, 131, 21));
        QFont font8;
        font8.setPointSize(14);
        font8.setBold(false);
        font8.setKerning(false);
        translateBy->setFont(font8);
        translateBy->setLayoutDirection(Qt::LeftToRight);
        translateBy->setAlignment(Qt::AlignCenter);
        rotateBy = new QLineEdit(centralwidget);
        rotateBy->setObjectName(QString::fromUtf8("rotateBy"));
        rotateBy->setGeometry(QRect(1150, 420, 131, 21));
        rotateBy->setFont(font8);
        rotateBy->setLayoutDirection(Qt::LeftToRight);
        rotateBy->setAlignment(Qt::AlignCenter);
        rzDown = new QPushButton(centralwidget);
        rzDown->setObjectName(QString::fromUtf8("rzDown"));
        rzDown->setGeometry(QRect(1100, 370, 31, 41));
        rzUp = new QPushButton(centralwidget);
        rzUp->setObjectName(QString::fromUtf8("rzUp"));
        rzUp->setGeometry(QRect(1020, 370, 31, 41));
        show_vertexes = new QCheckBox(centralwidget);
        show_vertexes->setObjectName(QString::fromUtf8("show_vertexes"));
        show_vertexes->setGeometry(QRect(780, 60, 161, 41));
        broken_lines = new QCheckBox(centralwidget);
        broken_lines->setObjectName(QString::fromUtf8("broken_lines"));
        broken_lines->setGeometry(QRect(780, 110, 161, 41));
        show_lines = new QCheckBox(centralwidget);
        show_lines->setObjectName(QString::fromUtf8("show_lines"));
        show_lines->setGeometry(QRect(780, 10, 161, 41));
        show_lines->setChecked(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 760, 611, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 660, 611, 31));
        line_thicc = new QSlider(centralwidget);
        line_thicc->setObjectName(QString::fromUtf8("line_thicc"));
        line_thicc->setGeometry(QRect(10, 850, 621, 25));
        line_thicc->setMinimum(1);
        line_thicc->setMaximum(25);
        line_thicc->setOrientation(Qt::Horizontal);
        vertex_thicc = new QSlider(centralwidget);
        vertex_thicc->setObjectName(QString::fromUtf8("vertex_thicc"));
        vertex_thicc->setGeometry(QRect(10, 710, 621, 25));
        vertex_thicc->setMinimum(1);
        vertex_thicc->setMaximum(25);
        vertex_thicc->setValue(5);
        vertex_thicc->setOrientation(Qt::Horizontal);
        smooth_vertexes = new QCheckBox(centralwidget);
        smooth_vertexes->setObjectName(QString::fromUtf8("smooth_vertexes"));
        smooth_vertexes->setGeometry(QRect(780, 160, 181, 41));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(640, 260, 177, 161));
        move_layout = new QGridLayout(gridLayoutWidget);
        move_layout->setObjectName(QString::fromUtf8("move_layout"));
        move_layout->setHorizontalSpacing(-1);
        move_layout->setVerticalSpacing(0);
        move_layout->setContentsMargins(0, 0, 0, 0);
        mRight = new QPushButton(gridLayoutWidget);
        mRight->setObjectName(QString::fromUtf8("mRight"));

        move_layout->addWidget(mRight, 2, 2, 1, 1);

        mDown = new QPushButton(gridLayoutWidget);
        mDown->setObjectName(QString::fromUtf8("mDown"));

        move_layout->addWidget(mDown, 3, 1, 1, 1);

        mUp = new QPushButton(gridLayoutWidget);
        mUp->setObjectName(QString::fromUtf8("mUp"));

        move_layout->addWidget(mUp, 0, 1, 1, 1);

        mForward = new QPushButton(gridLayoutWidget);
        mForward->setObjectName(QString::fromUtf8("mForward"));

        move_layout->addWidget(mForward, 0, 0, 1, 1);

        mLeft = new QPushButton(gridLayoutWidget);
        mLeft->setObjectName(QString::fromUtf8("mLeft"));

        move_layout->addWidget(mLeft, 2, 0, 1, 1);

        mBackward = new QPushButton(gridLayoutWidget);
        mBackward->setObjectName(QString::fromUtf8("mBackward"));

        move_layout->addWidget(mBackward, 0, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(670, 210, 221, 51));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Browse->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        model_name->setText(QString());
        line_color->setText(QCoreApplication::translate("MainWindow", "Set color", nullptr));
        background_color->setText(QCoreApplication::translate("MainWindow", "Set background color", nullptr));
        rRight->setText(QCoreApplication::translate("MainWindow", "\342\207\242", nullptr));
        rDown->setText(QCoreApplication::translate("MainWindow", "\342\207\243", nullptr));
        rUp->setText(QCoreApplication::translate("MainWindow", "\342\207\241", nullptr));
        rLeft->setText(QCoreApplication::translate("MainWindow", "\342\207\240", nullptr));
        gif->setText(QCoreApplication::translate("MainWindow", "Make gif", nullptr));
        changePerspective->setText(QCoreApplication::translate("MainWindow", "Change perspective", nullptr));
        centerModel->setText(QCoreApplication::translate("MainWindow", "Center model", nullptr));
        vertex_color->setText(QCoreApplication::translate("MainWindow", "Set vertex color", nullptr));
        takeJpeg->setText(QCoreApplication::translate("MainWindow", "screenshot jpeg", nullptr));
        takeBmp->setText(QCoreApplication::translate("MainWindow", "screenshot bmp", nullptr));
        translateBy->setText(QCoreApplication::translate("MainWindow", "1.0", nullptr));
        rotateBy->setText(QCoreApplication::translate("MainWindow", "1.0", nullptr));
        rzDown->setText(QCoreApplication::translate("MainWindow", "\342\206\230", nullptr));
        rzUp->setText(QCoreApplication::translate("MainWindow", "\342\206\226", nullptr));
        show_vertexes->setText(QCoreApplication::translate("MainWindow", "Show vertexes", nullptr));
        broken_lines->setText(QCoreApplication::translate("MainWindow", "Edged lines", nullptr));
        show_lines->setText(QCoreApplication::translate("MainWindow", "Show lines", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Line Thickness", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Vertex Thickness", nullptr));
        smooth_vertexes->setText(QCoreApplication::translate("MainWindow", "Smooth vertexes", nullptr));
        mRight->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        mDown->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        mUp->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        mForward->setText(QCoreApplication::translate("MainWindow", "\342\207\247", nullptr));
        mLeft->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        mBackward->setText(QCoreApplication::translate("MainWindow", "\342\207\251", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Move model", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
