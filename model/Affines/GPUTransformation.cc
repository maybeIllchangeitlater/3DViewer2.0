#include "GPUTransformation.h"
namespace s21 {

void GPUTransformation::ApplyTranslation(QMatrix4x4 &matrix,
                                         QVector<float> &vertex, float x,
                                         float y, float z) const {
  Q_UNUSED(vertex);
  matrix.translate(x, y, -2.5 + z);
}

void GPUTransformation::ApplyScaling(QMatrix4x4 &matrix, QVector<float> &vertex,
                                     float scale) const {
  Q_UNUSED(vertex);
  matrix.scale(scale);
}

void GPUTransformation::ApplyRotation(QMatrix4x4 &matrix,
                                      QVector<float> &vertex, float x, float y,
                                      float z) const {
  Q_UNUSED(vertex);
  matrix.rotate(y, 1.0, 0.0, 0.0f);
  matrix.rotate(x, 0.0, 1.0, 0.0f);
  matrix.rotate(z, 0.0, 0.0, 1.0f);
}

void GPUTransformation::MoveModel(QMatrix4x4 &matrix, QVector<float> &vertex,
                                  const Settings &settings) const {
  Q_UNUSED(vertex);
  matrix.setToIdentity();
  ApplyTranslation(matrix, vertex, settings.translation_x,
                   settings.translation_y, settings.translation_z);
  ApplyScaling(matrix, vertex, settings.scale);
  ApplyRotation(matrix, vertex, settings.rotation_x, settings.rotation_y,
                settings.rotation_z);
}

}  // namespace s21
