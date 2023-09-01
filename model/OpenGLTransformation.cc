#include "OpenGLTransformation.h"
namespace s21{

void OpenGLTransformation::ApplyTranslation(QMatrix4x4 &matrix, float x, float y, float z)
{
    matrix.translate(x, y, -2.5 + z);
}

void OpenGLTransformation::ApplyScaling(QMatrix4x4 &matrix, float scale)
{
    matrix.scale(scale);
}

void OpenGLTransformation::ApplyRotation(QMatrix4x4 &matrix, float x, float y, float z)
{
    matrix.rotate(y, 1.0, 0.0, 0.0f);
    matrix.rotate(x, 0.0, 1.0, 0.0f);
    matrix.rotate(z, 0.0, 0.0, 1.0f);
}

}
