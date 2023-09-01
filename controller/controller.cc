#include "controller.h"

namespace s21{

Controller::Controller(Model &model) : model_(model)
{

}
//template< class... Types>
void Controller::OpenFile(QString &filename)
{
    model_.ParseFile(filename);

}

//OpenGLWidget *Controller::Display_Model()
//{
//   return model_.DisplayModel();
//}

};
