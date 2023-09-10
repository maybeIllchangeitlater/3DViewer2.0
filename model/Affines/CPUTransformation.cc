#include "CPUTransformation.h"
namespace s21 {

void CPUTransformation::ApplyTranslation(QMatrix4x4 &matrix,
                                         QVector<float> &vertex, float x,
                                         float y, float z) const {
  Q_UNUSED(matrix);
  for (auto b_it = vertex.begin(), e_it = vertex.end(); b_it != e_it;) {
    *b_it++ += x;
    *b_it++ += y;
    *b_it++ += z;
  }
}

void CPUTransformation::ApplyScaling(QMatrix4x4 &matrix, QVector<float> &vertex,
                                     float scale) const {
  Q_UNUSED(matrix);
  for (auto &v : vertex) v *= scale;
}

void CPUTransformation::ApplyRotation(QMatrix4x4 &matrix,
                                      QVector<float> &vertex, float x, float y,
                                      float z) const {
  Q_UNUSED(matrix);
  std::swap(x, y);
  y /= 60;
  x /= 60;
  z /= 60;
  float sinx = std::sin(x);
  float cosx = std::cos(x);
  float siny = std::sin(-y);
  float cosy = std::cos(-y);
  float sinz = std::sin(z);
  float cosz = std::cos(z);
  if (y) {
    for (auto b_it = vertex.begin(), e_it = vertex.end(); b_it != e_it;
         b_it += 3) {
      double rem_cur = *b_it;
      *b_it = rem_cur * cosy - *(b_it + 2) * siny;
      *(b_it + 2) = rem_cur * siny + *(b_it + 2) * cosy;
    }
  }
  if (x) {
    for (auto b_it = vertex.begin(), e_it = vertex.end(); b_it != e_it;
         b_it += 3) {
      double rem_cur = *(b_it + 1);
      *(b_it + 1) = rem_cur * cosx - *(b_it + 2) * sinx;
      *(b_it + 2) = rem_cur * sinx + *(b_it + 2) * cosx;
    }
  }
  if (z) {
    for (auto b_it = vertex.begin(), e_it = vertex.end(); b_it != e_it;
         b_it += 3) {
      double rem_cur = *b_it;
      *b_it = rem_cur * cosz - *(b_it + 1) * sinz;
      *(b_it + 1) = rem_cur * sinz + *(b_it + 1) * cosz;
    }
  }
}

void CPUTransformation::MoveModel(QMatrix4x4 &matrix, QVector<float> &vertex,
                                  const Settings &settings) const {
  Q_UNUSED(matrix);
  ApplyScaling(matrix, vertex, settings.scale * 0.5);
  ApplyRotation(matrix, vertex, settings.rotation_x, settings.rotation_y,
                settings.rotation_z);
  ApplyTranslation(matrix, vertex, settings.translation_x,
                   settings.translation_y, settings.translation_z);
}

}  // namespace s21
