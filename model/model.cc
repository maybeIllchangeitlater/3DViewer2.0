#include "model.h"
#include <list>
namespace s21{
void Model::ParseFile(QString &filename)
{
//    vertex_.clear();
//    face_.clear();
    parser_.ParseFile(filename);
    filename =  filename.mid(filename.lastIndexOf("/") + 1).chopped(4) + "\n" +
            "Vertexes: " + QString::number(vertex_.size() / 3) +
            " Edges: " + QString::number(face_.size()/2);
}

//OpenGLWidget *Model::DisplayModel()
//{
//    gl_widget_ = new OpenGLWidget(vertex_, face_, settings_);
//    return gl_widget_;
//}
};
