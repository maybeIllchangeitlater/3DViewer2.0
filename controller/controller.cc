#include "controller.h"

namespace s21{

Controller::Controller(ObjParser &parser) : parser_(parser)
{

}
//template< class... Types>
void Controller::OpenFile(QString &filename)
{
    parser_.ParseFile(filename);

}

//OpenGLWidget *Controller::Display_Model()
//{
//   return model_.DisplayModel();
//}

};
