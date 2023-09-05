#ifndef CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#include <QOpenGLFunctions>
#include "parser.h"
#include "TransformationStrategy.h"
#include "OpenGLTransformation.h"
#include "settings.h"
#include "CPUTransformation.h"

namespace s21{
    class Controller{
       public:
           explicit Controller(ObjParser & parser, TransformationStrategy *transformer);
           void ParseFile(QString &filename);
           void MoveModel(QMatrix4x4& matrix, const Settings &settings);
           constexpr inline const QVector<unsigned int>& GetFaceConstRef() const{return face_;}
           constexpr inline const QVector<float>& GetVertexCopyConstRef() const{return vertex_;}
           constexpr inline const int ShaderVersion() const {return transformer_->GetShaderVersion();}

    private:
        ObjParser & parser_;
        TransformationStrategy *transformer_;
        QVector<float> vertex_;
        QVector<unsigned int> face_;
        QVector<float> vertex_copy_;

    };
}
#endif //CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
