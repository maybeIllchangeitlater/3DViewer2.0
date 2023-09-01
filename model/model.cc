#include "model.h"
namespace s21{
Controller::Controller(ObjParser &parser, TransformationStrategy *transformer) : parser_(parser),
    transformer_(transformer)
{

}

void Controller::ParseFile(QString &filename)
{
    parser_.ParseFile(filename, vertex_, face_);
}

void Controller::Translate(QMatrix4x4& matrix, float x, float y, float z){
    transformer_->ApplyTranslation(matrix, x, y, z);
}

void Controller::Scale(QMatrix4x4 &matrix, float scale)
{
    transformer_->ApplyScaling(matrix, scale);
}

void Controller::Rotate(QMatrix4x4 &matrix, float x, float y, float z)
{
    transformer_->ApplyRotation(matrix, x, y, z);
}



}
