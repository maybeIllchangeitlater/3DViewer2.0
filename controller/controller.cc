#include "controller.h"
namespace s21 {
Controller::Controller(ObjParser &parser, TransformationStrategy *transformer)
    : parser_(parser), transformer_(transformer) {
  QObject::connect(&parser_, SIGNAL(ParseOver(bool)), this, SLOT(Update(bool)));
}

void Controller::ParseFile(QString filename) const {
  parser_.SetFilename(filename);
  std::thread t1([this]() { parser_.ParseFile(); });
  t1.detach();
}

void Controller::MoveModel(QMatrix4x4 &matrix, const Settings &settings) {
  if (transformer_->GetShaderVersion() == 2) vertex_ = vertex_copy_;
  transformer_->MoveModel(matrix, vertex_, settings);
}

void Controller::Update(bool good_file) noexcept {
  vertex_ = parser_.GetTmpVertexConstRef();
  vertex_copy_ = vertex_;
  face_ = parser_.GetFaceConstRef();
  emit ParseOver(good_file);
}
}  // namespace s21
