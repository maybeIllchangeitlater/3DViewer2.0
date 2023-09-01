#ifndef CPP4_3DVIEWER_V2_0_MODEL_CPUTRANSFORMATION_H_
#define CPP4_3DVIEWER_V2_0_MODEL_CPUTRANSFORMATION_H_
#include "TransformationStrategy.h"
namespace s21{
    class CPUTransformation final: public TransformationStrategy{
    public:
     CPUTransformation() = default;
     ~CPUTransformation() override {};
     void ApplyTranslation(QMatrix4x4& matrix, float x, float y, float z) override;
     void ApplyScaling(QMatrix4x4& matrix, float scale) override;;
     void ApplyRotation(QMatrix4x4& matrix, float x, float y, float z) override;
};
}
#endif // CPP4_3DVIEWER_V2_0_MODEL_CPUTRANSFORMATION_H_
