#include "CPUTransformation.h"
namespace s21{

void CPUTransformation::ApplyTranslation(QMatrix4x4 &matrix, QVector<float> &vertex, float x, float y, float z)
{
    for(auto b_it = vertex.begin(), e_it = vertex.end(); b_it != e_it;){
        *b_it++ += x;
        *b_it++ += y;
        *b_it++ += z;
    }
}

void CPUTransformation::ApplyScaling(QMatrix4x4 &matrix, QVector<float> &vertex, float scale)
{
    for(auto& v : vertex)
        v *= scale;
}

void CPUTransformation::ApplyRotation(QMatrix4x4 &matrix, QVector<float> &vertex, float x, float y, float z)
{
    for(auto b_it = vertex.begin(), e_it = vertex.end(); b_it != e_it; b_it += 3){
          double rem_cur = *b_it;
          *b_it = rem_cur * std::cos(z) - *(b_it + 1) * std::sin(z);
          *(b_it + 1) = rem_cur * std::sin(z) +  *(b_it + 1) * std::cos(z);
        }


      for(auto b_it = vertex.begin(), e_it = vertex.end(); b_it != e_it; b_it += 3){
          double rem_cur = *(b_it + 1);
          *(b_it + 1) = rem_cur * std::cos(x) - *(b_it + 2) * std::sin(x);
          *(b_it + 2) = rem_cur * std::sin(x) + *(b_it + 2) * std::cos(x);
        }


      for(auto b_it = vertex.begin(), e_it = vertex.end(); b_it != e_it; b_it += 3){
          double rem_cur = *b_it;
          *b_it = rem_cur * std::cos(y) - *(b_it + 2) * std::sin(y);
          *(b_it + 2) = rem_cur * std::sin(y) + *(b_it + 2) * std::cos(y);
        }


}

void CPUTransformation::MoveModel(QMatrix4x4 &matrix, QVector<float> &vertex, const Settings &settings)
{
    ApplyScaling(matrix, vertex, settings.scale);
    ApplyRotation(matrix, vertex, settings.rotation_x, settings.rotation_y, settings.rotation_z);
    ApplyTranslation(matrix, vertex, settings.translation_x, settings.translation_y, settings.translation_z);
}



}


