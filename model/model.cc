#include "model.h"
namespace s21{
void Model::ParseFile(QString &filename)
{
    vertex_.clear();
    face_.clear();
    parser_.ParseFile(filename, vertex_, face_);
    filename =  filename.mid(filename.lastIndexOf("/") + 1).chopped(4) + "\n" +
            "Vertexes: " + QString::number(vertex_.size() / 3) +
            " Edges: " + QString::number(face_.size());
}

OpenGLWidget *Model::DisplayModel()
{
    gl_widget_ = new OpenGLWidget(vertex_, face_, settings_);
    return gl_widget_;
}
};
