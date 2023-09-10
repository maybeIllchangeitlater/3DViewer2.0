#ifndef CPP4_3DVIEWER_V2_0_MODEL_AFFINES_CPUTRANSFORMATION_H_
#define CPP4_3DVIEWER_V2_0_MODEL_AFFINES_CPUTRANSFORMATION_H_
#include "TransformationStrategy.h"
namespace s21 {
class CPUTransformation final : public TransformationStrategy {
 public:
  CPUTransformation() = default;
  ~CPUTransformation() override{};
  void MoveModel(QMatrix4x4& matrix, QVector<float>& vertex,
                 const Settings& settings) const override;
  int GetShaderVersion() const noexcept override { return 2; };

 protected:
  void ApplyTranslation(QMatrix4x4& matrix, QVector<float>& vertex, float x,
                        float y, float z) const override;
  void ApplyScaling(QMatrix4x4& matrix, QVector<float>& vertex,
                    float scale) const override;
  void ApplyRotation(QMatrix4x4& matrix, QVector<float>& vertex, float x,
                     float y, float z) const override;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_MODEL_AFFINES_CPUTRANSFORMATION_H_
