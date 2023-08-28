#ifndef CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
#define CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
//#include "ui_mainwindow.h"
#include <iostream>
#include <QCloseEvent>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDir>

namespace s21{
class Settings{

public:
    Settings();
    void SaveSettings();
    void LoadSettings();
    QColor color;
    QColor back_color;
    QColor vertex_color;
    bool orth;
    bool smooth_vertexes;
    bool vertexes_shown;
    bool lines_shown;
    bool broken_lines;
    int line_width;
    int point_size;
private:
//     Ui::MainWindow *ui_;
};
}
#endif //CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H_
