#ifndef CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#include <QOpenGLFunctions>
#include "parser.h"
#include "TransformationStrategy.h"
#include "OpenGLTransformation.h"
#include "CPUTransformation.h"

namespace s21{
    class Controller{
       public:
            explicit Controller(ObjParser & parser, TransformationStrategy *transformer);
           void ParseFile(QString &filename);
           void Translate(QMatrix4x4& matrix, float x, float y, float z);
           void Scale(QMatrix4x4& matrix, float scale);
           void Rotate(QMatrix4x4& matrix, float x, float y, float z);
           constexpr inline const QVector<int>& GetFaceConstRef() const{return face_;}
           constexpr inline const QVector<float>& GetVertexCopyConstRef() const{return vertex_;}

    private:
        ObjParser & parser_;
        TransformationStrategy *transformer_;
        QVector<float> vertex_;
        QVector<int> face_;
        QVector<float> vertex_copy_;

    };
}
#endif //CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
