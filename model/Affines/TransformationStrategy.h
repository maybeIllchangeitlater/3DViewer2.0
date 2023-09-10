#ifndef CPP4_3DVIEWER_V2_0_MODEL_AFFINES_TRANSLATIONSTRATEGY_H_
#define CPP4_3DVIEWER_V2_0_MODEL_AFFINES_TRANSLATIONSTRATEGY_H_
#include "../../view/settings.h"
#include "QtGui/qmatrix4x4.h"
namespace s21 {
class TransformationStrategy {
 public:
  TransformationStrategy() = default;
  virtual ~TransformationStrategy() = default;
  virtual void MoveModel(QMatrix4x4& matrix, QVector<float>& vertex,
                         const Settings& settings) const = 0;
  /**
   * @brief GetVertexShader
   * @param version 1 - for GPU transformations, 2 - for CPU transformations
   */
  virtual int GetShaderVersion() const noexcept = 0;

 protected:
  virtual void ApplyTranslation(QMatrix4x4& matrix, QVector<float>& vertex,
                                float x, float y, float z) const = 0;
  virtual void ApplyScaling(QMatrix4x4& matrix, QVector<float>& vertex,
                            float scale) const = 0;
  virtual void ApplyRotation(QMatrix4x4& matrix, QVector<float>& vertex,
                             float x, float y, float z) const = 0;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_MODEL_AFFINES_TRANSLATIONSTRATEGY_H_
