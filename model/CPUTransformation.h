#ifndef CPP4_3DVIEWER_V2_0_MODEL_CPUTRANSFORMATION_H_
#define CPP4_3DVIEWER_V2_0_MODEL_CPUTRANSFORMATION_H_
#include "TransformationStrategy.h"
namespace s21{
    class CPUTransformation final: public TransformationStrategy{
    public:
     CPUTransformation() = default;
     ~CPUTransformation() override {};
     void ApplyTranslation(QMatrix4x4& matrix, QVector<float>& vertex, float x, float y, float z) override;
     void ApplyScaling(QMatrix4x4& matrix, QVector<float>& vertex, float scale) override;
     void ApplyRotation(QMatrix4x4& matrix,  QVector<float>& vertex, float x, float y, float z) override;
     void MoveModel(QMatrix4x4& matrix, QVector<float>& vertex, const Settings& settings) override;
     inline int GetShaderVersion() override {return 2;};
};
}
#endif // CPP4_3DVIEWER_V2_0_MODEL_CPUTRANSFORMATION_H_
