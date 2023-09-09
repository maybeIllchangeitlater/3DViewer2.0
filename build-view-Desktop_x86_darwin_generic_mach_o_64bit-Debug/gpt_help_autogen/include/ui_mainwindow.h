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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QLabel *model_name;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QSlider *line_thicc;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QSlider *vertex_thicc;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_5;
    QSlider *scale_slider;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QGridLayout *move_layout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *rotateBy;
    QPushButton *rzUp;
    QPushButton *rLeft;
    QPushButton *rRight;
    QPushButton *rUp;
    QPushButton *rzDown;
    QPushButton *rDown;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *show_lines;
    QCheckBox *show_vertexes;
    QCheckBox *broken_lines;
    QCheckBox *smooth_vertexes;
    QSpacerItem *verticalSpacer;
    QGridLayout *move_layout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *translateBy;
    QPushButton *mForward;
    QPushButton *mLeft;
    QPushButton *mRight;
    QPushButton *mDown;
    QPushButton *mBackward;
    QPushButton *mUp;
    QVBoxLayout *verticalLayout_4;
    QPushButton *Browse;
    QPushButton *changeShader;
    QPushButton *changePerspective;
    QVBoxLayout *verticalLayout_2;
    QPushButton *line_color;
    QPushButton *vertex_color;
    QPushButton *background_color;
    QVBoxLayout *verticalLayout_3;
    QPushButton *takeJpeg;
    QPushButton *takeBmp;
    QPushButton *gif;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 734);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1300, 734));
        MainWindow->setMaximumSize(QSize(1300, 734));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setMinimumSize(QSize(1300, 706));
        centralwidget->setMaximumSize(QSize(1800, 740));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 60, 631, 501));
        viewer_layout = new QVBoxLayout(verticalLayoutWidget);
        viewer_layout->setObjectName(QString::fromUtf8("viewer_layout"));
        viewer_layout->setSizeConstraint(QLayout::SetNoConstraint);
        viewer_layout->setContentsMargins(0, 0, 0, 0);
        model_name = new QLabel(centralwidget);
        model_name->setObjectName(QString::fromUtf8("model_name"));
        model_name->setGeometry(QRect(10, 10, 631, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        model_name->setFont(font1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 570, 1271, 132));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_7->addWidget(label);

        line_thicc = new QSlider(layoutWidget);
        line_thicc->setObjectName(QString::fromUtf8("line_thicc"));
        line_thicc->setMinimum(1);
        line_thicc->setMaximum(25);
        line_thicc->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(line_thicc);


        gridLayout_3->addLayout(verticalLayout_7, 0, 1, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_6->addWidget(label_2);

        vertex_thicc = new QSlider(layoutWidget);
        vertex_thicc->setObjectName(QString::fromUtf8("vertex_thicc"));
        vertex_thicc->setMinimum(1);
        vertex_thicc->setMaximum(25);
        vertex_thicc->setValue(5);
        vertex_thicc->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(vertex_thicc);


        gridLayout_3->addLayout(verticalLayout_6, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_8->addWidget(label_5);

        scale_slider = new QSlider(layoutWidget);
        scale_slider->setObjectName(QString::fromUtf8("scale_slider"));
        scale_slider->setEnabled(true);
        scale_slider->setMinimumSize(QSize(0, 25));
        QPalette palette;
        QBrush brush(QColor(211, 163, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush);
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush1);
        scale_slider->setPalette(palette);
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setKerning(true);
        scale_slider->setFont(font2);
        scale_slider->setMouseTracking(false);
        scale_slider->setTabletTracking(false);
        scale_slider->setAcceptDrops(false);
        scale_slider->setAutoFillBackground(false);
        scale_slider->setStyleSheet(QString::fromUtf8(""));
        scale_slider->setMaximum(200);
        scale_slider->setSliderPosition(100);
        scale_slider->setOrientation(Qt::Horizontal);
        scale_slider->setInvertedAppearance(false);
        scale_slider->setInvertedControls(false);

        verticalLayout_8->addWidget(scale_slider);


        verticalLayout_5->addLayout(verticalLayout_8);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(654, 15, 631, 551));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        move_layout_3 = new QGridLayout();
        move_layout_3->setObjectName(QString::fromUtf8("move_layout_3"));
        move_layout_3->setHorizontalSpacing(-1);
        move_layout_3->setVerticalSpacing(0);
        move_layout_3->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(-1, -1, 0, 0);
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_4);

        rotateBy = new QLineEdit(layoutWidget1);
        rotateBy->setObjectName(QString::fromUtf8("rotateBy"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setKerning(false);
        rotateBy->setFont(font3);
        rotateBy->setLayoutDirection(Qt::LeftToRight);
        rotateBy->setAlignment(Qt::AlignCenter);
        rotateBy->setDragEnabled(false);
        rotateBy->setReadOnly(false);
        rotateBy->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(rotateBy);


        move_layout_3->addLayout(horizontalLayout_2, 0, 0, 1, 3);

        rzUp = new QPushButton(layoutWidget1);
        rzUp->setObjectName(QString::fromUtf8("rzUp"));
        rzUp->setMinimumSize(QSize(0, 20));
        rzUp->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        rzUp->setFlat(true);

        move_layout_3->addWidget(rzUp, 5, 0, 1, 1);

        rLeft = new QPushButton(layoutWidget1);
        rLeft->setObjectName(QString::fromUtf8("rLeft"));
        rLeft->setMinimumSize(QSize(0, 20));
        rLeft->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        rLeft->setFlat(true);

        move_layout_3->addWidget(rLeft, 3, 0, 1, 1);

        rRight = new QPushButton(layoutWidget1);
        rRight->setObjectName(QString::fromUtf8("rRight"));
        rRight->setMinimumSize(QSize(0, 20));
        rRight->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        rRight->setFlat(true);

        move_layout_3->addWidget(rRight, 3, 2, 1, 1);

        rUp = new QPushButton(layoutWidget1);
        rUp->setObjectName(QString::fromUtf8("rUp"));
        rUp->setMinimumSize(QSize(0, 20));
        rUp->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        rUp->setFlat(true);

        move_layout_3->addWidget(rUp, 1, 1, 1, 1);

        rzDown = new QPushButton(layoutWidget1);
        rzDown->setObjectName(QString::fromUtf8("rzDown"));
        rzDown->setMinimumSize(QSize(0, 20));
        rzDown->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        rzDown->setFlat(true);

        move_layout_3->addWidget(rzDown, 1, 2, 1, 1);

        rDown = new QPushButton(layoutWidget1);
        rDown->setObjectName(QString::fromUtf8("rDown"));
        rDown->setMinimumSize(QSize(0, 20));
        rDown->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        rDown->setFlat(true);

        move_layout_3->addWidget(rDown, 5, 1, 1, 1);


        gridLayout_4->addLayout(move_layout_3, 4, 1, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAutoFillBackground(false);
        label_4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_4->addWidget(label_4, 3, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_4->addWidget(label_3, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        show_lines = new QCheckBox(layoutWidget1);
        show_lines->setObjectName(QString::fromUtf8("show_lines"));
        show_lines->setChecked(true);

        verticalLayout->addWidget(show_lines);

        show_vertexes = new QCheckBox(layoutWidget1);
        show_vertexes->setObjectName(QString::fromUtf8("show_vertexes"));

        verticalLayout->addWidget(show_vertexes);

        broken_lines = new QCheckBox(layoutWidget1);
        broken_lines->setObjectName(QString::fromUtf8("broken_lines"));

        verticalLayout->addWidget(broken_lines);

        smooth_vertexes = new QCheckBox(layoutWidget1);
        smooth_vertexes->setObjectName(QString::fromUtf8("smooth_vertexes"));

        verticalLayout->addWidget(smooth_vertexes);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 0, 1, 1);

        move_layout = new QGridLayout();
        move_layout->setObjectName(QString::fromUtf8("move_layout"));
        move_layout->setHorizontalSpacing(-1);
        move_layout->setVerticalSpacing(0);
        move_layout->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer_3);

        translateBy = new QLineEdit(layoutWidget1);
        translateBy->setObjectName(QString::fromUtf8("translateBy"));
        translateBy->setFont(font3);
        translateBy->setLayoutDirection(Qt::LeftToRight);
        translateBy->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(translateBy);


        move_layout->addLayout(horizontalLayout, 0, 0, 1, 3);

        mForward = new QPushButton(layoutWidget1);
        mForward->setObjectName(QString::fromUtf8("mForward"));
        mForward->setMinimumSize(QSize(0, 20));
        mForward->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        mForward->setAutoDefault(false);
        mForward->setFlat(true);

        move_layout->addWidget(mForward, 4, 0, 1, 1);

        mLeft = new QPushButton(layoutWidget1);
        mLeft->setObjectName(QString::fromUtf8("mLeft"));
        mLeft->setMinimumSize(QSize(0, 20));
        mLeft->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        mLeft->setAutoDefault(false);
        mLeft->setFlat(true);

        move_layout->addWidget(mLeft, 3, 0, 1, 1);

        mRight = new QPushButton(layoutWidget1);
        mRight->setObjectName(QString::fromUtf8("mRight"));
        mRight->setMinimumSize(QSize(0, 20));
        mRight->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        mRight->setAutoDefault(false);
        mRight->setFlat(true);

        move_layout->addWidget(mRight, 3, 2, 1, 1);

        mDown = new QPushButton(layoutWidget1);
        mDown->setObjectName(QString::fromUtf8("mDown"));
        mDown->setMinimumSize(QSize(0, 20));
        mDown->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        mDown->setAutoDefault(false);
        mDown->setFlat(true);

        move_layout->addWidget(mDown, 4, 1, 1, 1);

        mBackward = new QPushButton(layoutWidget1);
        mBackward->setObjectName(QString::fromUtf8("mBackward"));
        mBackward->setMinimumSize(QSize(0, 20));
        mBackward->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        mBackward->setAutoDefault(false);
        mBackward->setFlat(true);

        move_layout->addWidget(mBackward, 2, 2, 1, 1);

        mUp = new QPushButton(layoutWidget1);
        mUp->setObjectName(QString::fromUtf8("mUp"));
        mUp->setMinimumSize(QSize(0, 20));
        mUp->setStyleSheet(QString::fromUtf8("margin: 5px;"));
        mUp->setAutoDefault(false);
        mUp->setFlat(true);

        move_layout->addWidget(mUp, 2, 1, 1, 1);


        gridLayout_4->addLayout(move_layout, 4, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        Browse = new QPushButton(layoutWidget1);
        Browse->setObjectName(QString::fromUtf8("Browse"));
        QFont font4;
        font4.setPointSize(23);
        font4.setBold(false);
        Browse->setFont(font4);
        Browse->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(Browse);

        changeShader = new QPushButton(layoutWidget1);
        changeShader->setObjectName(QString::fromUtf8("changeShader"));
        QFont font5;
        font5.setPointSize(17);
        font5.setBold(false);
        changeShader->setFont(font5);
        changeShader->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(changeShader);

        changePerspective = new QPushButton(layoutWidget1);
        changePerspective->setObjectName(QString::fromUtf8("changePerspective"));
        changePerspective->setFont(font5);
        changePerspective->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(changePerspective);


        gridLayout_4->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout_2->setSpacing(-1);
#endif
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        line_color = new QPushButton(layoutWidget1);
        line_color->setObjectName(QString::fromUtf8("line_color"));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(false);
        line_color->setFont(font6);
        line_color->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(line_color);

        vertex_color = new QPushButton(layoutWidget1);
        vertex_color->setObjectName(QString::fromUtf8("vertex_color"));
        vertex_color->setFont(font6);
        vertex_color->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(vertex_color);

        background_color = new QPushButton(layoutWidget1);
        background_color->setObjectName(QString::fromUtf8("background_color"));
        background_color->setFont(font6);
        background_color->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(background_color);


        gridLayout_4->addLayout(verticalLayout_2, 1, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        takeJpeg = new QPushButton(layoutWidget1);
        takeJpeg->setObjectName(QString::fromUtf8("takeJpeg"));
        takeJpeg->setFont(font5);
        takeJpeg->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(takeJpeg);

        takeBmp = new QPushButton(layoutWidget1);
        takeBmp->setObjectName(QString::fromUtf8("takeBmp"));
        takeBmp->setFont(font5);
        takeBmp->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(takeBmp);

        gif = new QPushButton(layoutWidget1);
        gif->setObjectName(QString::fromUtf8("gif"));
        gif->setFont(font5);
        gif->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(gif);


        gridLayout_4->addLayout(verticalLayout_3, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        mForward->setDefault(false);
        mLeft->setDefault(false);
        mRight->setDefault(false);
        mDown->setDefault(false);
        mBackward->setDefault(false);
        mUp->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        model_name->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Line Thickness", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Vertex Thickness", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Model Scale", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "scale", nullptr));
        rotateBy->setText(QCoreApplication::translate("MainWindow", "1.0", nullptr));
        rzUp->setText(QCoreApplication::translate("MainWindow", "\342\206\226", nullptr));
        rLeft->setText(QCoreApplication::translate("MainWindow", "\342\207\240", nullptr));
        rRight->setText(QCoreApplication::translate("MainWindow", "\342\207\242", nullptr));
        rUp->setText(QCoreApplication::translate("MainWindow", "\342\207\241", nullptr));
        rzDown->setText(QCoreApplication::translate("MainWindow", "\342\206\226", nullptr));
        rDown->setText(QCoreApplication::translate("MainWindow", "\342\207\243", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Rotate model", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Move model", nullptr));
        show_lines->setText(QCoreApplication::translate("MainWindow", "  show lines", nullptr));
        show_vertexes->setText(QCoreApplication::translate("MainWindow", "  show vertexes", nullptr));
        broken_lines->setText(QCoreApplication::translate("MainWindow", "  edged lines", nullptr));
        smooth_vertexes->setText(QCoreApplication::translate("MainWindow", "  smooth vertexes", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "scale", nullptr));
        translateBy->setText(QCoreApplication::translate("MainWindow", "1.0", nullptr));
        mForward->setText(QCoreApplication::translate("MainWindow", "\342\207\247", nullptr));
        mLeft->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        mRight->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        mDown->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        mBackward->setText(QCoreApplication::translate("MainWindow", "\342\207\251", nullptr));
        mUp->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        Browse->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        changeShader->setText(QCoreApplication::translate("MainWindow", "changeShader", nullptr));
        changePerspective->setText(QCoreApplication::translate("MainWindow", "change perspective", nullptr));
        line_color->setText(QCoreApplication::translate("MainWindow", "set line color", nullptr));
        vertex_color->setText(QCoreApplication::translate("MainWindow", "set vertex color", nullptr));
        background_color->setText(QCoreApplication::translate("MainWindow", "set background color", nullptr));
        takeJpeg->setText(QCoreApplication::translate("MainWindow", "screenshot jpeg", nullptr));
        takeBmp->setText(QCoreApplication::translate("MainWindow", "screenshot bmp", nullptr));
        gif->setText(QCoreApplication::translate("MainWindow", "make gif", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
