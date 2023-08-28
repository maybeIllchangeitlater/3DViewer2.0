#ifndef CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#include "../model/model.h"
#include <tuple>
namespace s21{
    class Controller {
//        Q_OBJECT
    public:
        explicit Controller(ObjParser &parser);
//        template< class... Types>
        void OpenFile(QString& filename);
        constexpr inline const QVector<float>& GetVertexConstRef() const{return parser_.GetVertexConstRef();}
        constexpr inline const QVector<int>& GetFaceConstRef() const{return parser_.GetFaceConstRef();}
//        OpenGLWidget * Display_Model();



    private:
        ObjParser& parser_;

    };
}
#endif //CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
