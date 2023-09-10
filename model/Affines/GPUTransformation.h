#ifndef CPP4_3DVIEWER_V2_0_MODEL_AFFINES_GPUTRANSFORMATION_H_
#define CPP4_3DVIEWER_V2_0_MODEL_AFFINES_GPUTRANSFORMATION_H_
#include <QOpenGLFunctions>

#include "TransformationStrategy.h"
namespace s21 {
class GPUTransformation final : public TransformationStrategy,
                                protected QOpenGLFunctions {
 public:
  GPUTransformation() = default;
  ~GPUTransformation() override{};
  void MoveModel(QMatrix4x4& matrix, QVector<float>& vertex,
                 const Settings& settings) const override;
  int GetShaderVersion() const noexcept override { return 1; };

 protected:
  void ApplyTranslation(QMatrix4x4& matrix, QVector<float>& vertex, float x,
                        float y, float z) const override;
  void ApplyScaling(QMatrix4x4& matrix, QVector<float>& vertex,
                    float scale) const override;
  void ApplyRotation(QMatrix4x4& matrix, QVector<float>& vertex, float x,
                     float y, float z) const override;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_MODEL_AFFINES_GPUTRANSFORMATION_H_
