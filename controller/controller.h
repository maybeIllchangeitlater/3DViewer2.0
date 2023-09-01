#ifndef CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#include "../model/model.h"
namespace s21{
    class Controller {
//        Q_OBJECT
    public:
        explicit Controller(Model& model);
        void OpenFile(QString& filename);
        constexpr inline const QVector<float>& GetVertexConstRef() const{return model_.GetVertexConstRef();}
        constexpr inline const QVector<int>& GetFaceConstRef() const{return model_.GetFaceConstRef();}
//        OpenGLWidget * Display_Model();



    private:
        Model& model_;

    };
}
#endif //CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
