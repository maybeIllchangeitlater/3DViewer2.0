#ifndef CPP4_3DVIEWER_V2_0_MODEL_TRANSLATIONSTRATEGY_H_
#define CPP4_3DVIEWER_V2_0_MODEL_TRANSLATIONSTRATEGY_H_
#include "QtGui/qmatrix4x4.h"
#include "settings.h"
namespace s21{
    class TransformationStrategy{
    public:
        TransformationStrategy() = default;
        virtual ~TransformationStrategy() = default;
         virtual void ApplyTranslation(QMatrix4x4& matrix, QVector<float>& vertex,float x, float y, float z) = 0;
         virtual void ApplyScaling(QMatrix4x4& matrix, QVector<float>& vertex, float scale) = 0;
         virtual void ApplyRotation(QMatrix4x4& matrix, QVector<float>& vertex, float x, float y, float z) = 0;
         virtual void MoveModel(QMatrix4x4& matrix, QVector<float>& vertex, const Settings& settings) = 0;
         virtual int GetShaderVersion() = 0;
    };
}
#endif // CPP4_3DVIEWER_V2_0_MODEL_TRANSLATIONSTRATEGY_H_
