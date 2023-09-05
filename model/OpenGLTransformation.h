#ifndef CPP4_3DVIEWER_V2_0_MODEL_OPENGLTRANSFORMATION_H_
#define CPP4_3DVIEWER_V2_0_MODEL_OPENGLTRANSFORMATION_H_
#include <QOpenGLFunctions>
#include "TransformationStrategy.h"
namespace s21{
class OpenGLTransformation final:  public TransformationStrategy, protected QOpenGLFunctions{
public:
    OpenGLTransformation() = default;
    ~OpenGLTransformation() = default;
    void ApplyTranslation(QMatrix4x4& matrix, QVector<float>& vertex, float x, float y, float z) override;
    void ApplyScaling(QMatrix4x4& matrix, QVector<float>& vertex, float scale) override;
    void ApplyRotation(QMatrix4x4& matrix,  QVector<float>& vertex, float x, float y, float z) override;
    void MoveModel(QMatrix4x4& matrix, QVector<float>& vertex, const Settings& settings) override;
    inline int GetShaderVersion() override {return 1;};
};
}
#endif //CPP4_3DVIEWER_V2_0_MODEL_OOPENGLTRANSFORMATION_H_ //минимальное остовное дерево
