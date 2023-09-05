#include "model.h"
namespace s21{
Controller::Controller(ObjParser &parser, TransformationStrategy *transformer) : parser_(parser),
    transformer_(transformer)
{

}

void Controller::ParseFile(QString &filename)
{
    parser_.ParseFile(filename, vertex_, face_);
    vertex_copy_ = vertex_;
}

void Controller::MoveModel(QMatrix4x4 &matrix, const Settings &settings)
{
   if(transformer_->GetShaderVersion() == 2)
       vertex_ = vertex_copy_;
    transformer_->MoveModel(matrix, vertex_, settings);
}


}
