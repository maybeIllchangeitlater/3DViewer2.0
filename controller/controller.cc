#include "controller.h"

namespace s21{

Controller::Controller(Model &model) : model_(model)
{

}

bool Controller::OpenFile(QString &filename)
{   try{
    model_.ParseFile(filename);
    }catch(std::exception e){
        filename = e.what();
        return false;
    }return true;

}

OpenGLWidget *Controller::Display_Model()
{
   return model_.DisplayModel();
}

};
