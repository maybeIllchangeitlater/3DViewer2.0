#ifndef CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#include <QOpenGLFunctions>
#include "parser.h"
#include "TransformationStrategy.h"
#include "OpenGLTransformation.h"
#include "settings.h"
#include "CPUTransformation.h"
#include "ShaderState.h"
#include "ShaderNoGeometry.h"
#include "ShaderPointsOnly.h"
#include "ShadersEverythingButSlow.h"
#include "ShaderCustomizableLines.h"
#include <thread>

namespace s21{
    class Controller : public QObject{

        Q_OBJECT

       public:
           explicit Controller(ObjParser & parser, TransformationStrategy *transformer, ShaderState * shader);
           void ParseFile(QString filename) const;
           void MoveModel(QMatrix4x4& matrix, const Settings &settings);
           void SwapShader(ShaderState * shader){shader_ = shader;}
           const char * GetVertexShader() const{return shader_->GetVertexShader(GetVertexShaderVersion());}
           const char * GetGeometryShader() const{return shader_->GetGeometryShader();};
           const char * GetFragmentShader() const{return shader_->GetFragmentShader();};
           constexpr inline const QVector<unsigned int>& GetFaceConstRef() const{return face_;}
           constexpr inline const QVector<float>& GetVertexCopyConstRef() const{return vertex_;}
           constexpr inline const int GetVertexShaderVersion() const{return transformer_->GetShaderVersion();}

    signals:
        void ParseOver(bool);

    public slots:
        void Update(bool);

    private:
        ObjParser & parser_;
        TransformationStrategy *transformer_;
        ShaderState * shader_;
        QVector<float> vertex_;
        QVector<unsigned int> face_;
        QVector<float> vertex_copy_;

    };
}
#endif //CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
