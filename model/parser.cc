#include "parser.h"

#include <fstream>
#include <iostream>
namespace s21 {

void s21::ObjParser::ParseFile() {
  vertices_data_.clear();
  tmp_normal_.clear();
  tmp_face_vertex_.clear();
  tmp_face_normal_.clear();

  QFile file(filename_);
  if (!file.exists() || !file.open(QIODevice::ReadOnly)) {
    file.close();
    emit ParseOver(false);
    return;
  }

  while (!file.atEnd()) {
    auto data(file.readLine());
    if (data[0] == 'v' && data[1] == ' ') {
        vertices_data_.emplaceBack();
      if (!PushPoint(data, vertices_data_.back().vertex)) {
        file.close();
        emit ParseOver(false);
        return;
      }
    } else if (data[0] == 'f' && data[1] == ' ') {
      if (!PushFace(data)) {
        file.close();
        emit ParseOver(false);
        return;
      }
    } else if (data[0] == 'v' && data[1] == 'n'){
        tmp_normal_.emplaceBack();
        if(!PushPoint(data, tmp_normal_.back())){
            file.close();
            emit ParseOver(false);
            return;
        }
    }
  }
  file.close();
  if(tmp_face_normal_.size() != tmp_face_vertex_.size()){
      emit ParseOver(false);
      return;
  }
  CombineData();
  ChangeFilename();
  *(std::max_element(tmp_face_vertex_.begin(), tmp_face_vertex_.end())) >
          (vertices_data_.size() / 3 - 1)
      ? emit ParseOver(false)
      : emit ParseOver(true);
  emit ParseOver(true);
}

template<typename Coordinatable>
bool ObjParser::PushPoint(QByteArray &data, Coordinatable &target) {
  auto cstr = data.data();
  size_t size = 0, sizeline_counter = 0;
  while (*cstr != EOF && *cstr != '\n') {
    while (
        !(std::isdigit(*cstr) || *cstr == '.' || *cstr == '-' || *cstr == '+'))
      ++cstr;
    while (std::isdigit(*(cstr + size)) || *(cstr + size) == '.' ||
           *(cstr + size) == '-' || *(cstr + size) == '+')
      ++size;
    target[sizeline_counter] = std::stof(cstr);
    cstr += size;
    size = 0;
    ++sizeline_counter;
  }
  return sizeline_counter == 3;
}

bool ObjParser::PushFace(QByteArray &data) {
  size_t i = 0;
  auto cstr = data.data();
  size_t n = data.size();

  SkipUntilNextDigit(i, n, cstr);
  if (*cstr == '\n') return false;
  int first_vert = std::stoi(cstr) - 1;
  tmp_face_vertex_.push_back(first_vert);

  SkipUntilNextFace(i, n, cstr);
  if (*cstr == '\n') return false;
  int first_texture = std::stoi(cstr) - 1;
  tmp_face_texture_.push_back(first_texture);

  SkipUntilNextFace(i, n, cstr);
  if (*cstr == '\n') return false;
  int first_normal = std::stoi(cstr) - 1;
  tmp_face_normal_.push_back(first_normal);

  SkipUntilNextDigit(i, n, cstr);
  int face;
  while (i < n) {
    face = std::stoi(cstr) - 1;
    tmp_face_vertex_.push_back(face);
    tmp_face_vertex_.push_back(face);
    SkipUntilNextFace(i, n, cstr);

    face = std::stoi(cstr) - 1;
    tmp_face_texture_.push_back(face);
    tmp_face_texture_.push_back(face);
    SkipUntilNextFace(i, n, cstr);

    face = std::stoi(cstr) - 1;
    tmp_face_normal_.push_back(face);
    tmp_face_normal_.push_back(face);
    SkipUntilNextDigit(i, n, cstr);
  }
  tmp_face_vertex_.push_back(first_vert);
  tmp_face_texture_.push_back(first_texture);
  tmp_face_normal_.push_back(first_normal);
  return true;
}

void ObjParser::CombineData()
{
    for(size_t i = 0; i < tmp_face_normal_.size(); ++i){
        vertices_data_[tmp_face_vertex_[i]].normal = std::move(tmp_normal_[tmp_face_normal_[i]]);
    }
}

void ObjParser::SkipUntilNextDigit(size_t &index, size_t data_size, char *data)
{
    while (index < data_size && !std::isspace(*data)) {
      ++data;
      ++index;
    }
    while (index < data_size && !(std::isdigit(*data))) {
      ++data;
      ++index;
    }
}

void ObjParser::SkipUntilNextFace(size_t &index, size_t data_size, char *data)
{
    while (index < data_size && *data != '/'){
        ++data;
        ++index;
    }
}



void ObjParser::ChangeFilename() noexcept {
  filename_ = filename_.mid(filename_.lastIndexOf("/") + 1).chopped(4) + "\n" +
              "Vertexes: " + QString::number(vertices_data_.size() / 3) +
              " Edges: " + QString::number(tmp_face_vertex_.size() / 2);
}
}  // namespace s21
