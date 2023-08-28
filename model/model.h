#ifndef CPP4_3DVIEWER_V2_0_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_MODEL_MODEL_H_

#include <QDir>
#include "widget.h"
#include "parser.h"
namespace s21{
    class Model{
//        Q_OBJECT
    public:
        void ParseFile(QString& filename);
        OpenGLWidget * DisplayModel();
    private:
        bool ValidateFile(QString& filename);
        ObjParser parser_;
        QVector<double> vertex_;
        QVector<int> face_;
        OpenGLWidget * gl_widget_;
        Settings settings_;
    };
}
#endif //CPP4_3DVIEWER_V2_0_MODEL_MODEL_H_
