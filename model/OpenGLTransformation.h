#ifndef CPP4_3DVIEWER_V2_0_MODEL_OPENGLTRANSFORMATION_H_
#define CPP4_3DVIEWER_V2_0_MODEL_OPENGLTRANSFORMATION_H_
#include <QOpenGLFunctions>
#include "TransformationStrategy.h"
namespace s21{
class OpenGLTransformation final:  public TransformationStrategy, protected QOpenGLFunctions{
public:
    OpenGLTransformation() = default;
    ~OpenGLTransformation() = default;
    void ApplyTranslation(QMatrix4x4& matrix, float x, float y, float z) override;
    void ApplyScaling(QMatrix4x4& matrix, float scale) override;
    void ApplyRotation(QMatrix4x4& matrix,float x, float y, float z) override;
};
}
#endif //CPP4_3DVIEWER_V2_0_MODEL_OOPENGLTRANSFORMATION_H_
