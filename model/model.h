#ifndef CPP4_3DVIEWER_V2_0_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_MODEL_MODEL_H_

#include <QDir>
#include "parser.h"
#include "settings.h"
namespace s21{
    class Model{
    public:
        void ParseFile(QString& filename);
//        constexpr inline const QVector<float>& GetVertexConstRef() const noexcept{
//            return vertex_;
//        }
//        constexpr inline const QVector<int>& GetFaceConstRef() const noexcept{
//            return face_;
//        }
//        OpenGLWidget * DisplayModel();
    private:
        ObjParser parser_; //change model to parser
//        QVector<float> vertex_;
//        QVector<int> face_;
    };
}
#endif //CPP4_3DVIEWER_V2_0_MODEL_MODEL_H_
