#include "parser.h"

#include <fstream>
#include <iostream>
namespace s21 {

void s21::ObjParser::ParseFile() {
  Clear();

  QFile file(filename_);
  if (!file.exists() || !file.open(QIODevice::ReadOnly)) {
    file.close();
    emit ParseOver(false);
    return;
  }

  AddZeros();

  while (!file.atEnd()) {
    QByteArray data(file.readLine());
    if (data[0] == 'v' && data[1] == ' ') {
      if (PushPoint(data, tmp_vertex_) != 3) {
        file.close();
        emit ParseOver(false);
        return;
      }
    } else if (data[0] == 'v' && data[1] == 'n'){
        if(PushPoint(data, tmp_normal_) != 3){
            file.close();
            emit ParseOver(false);
            return;
        }
    } else if(data[0] == 'v' && data[1] == 't'){
        if(PushPoint(data, tmp_texture_) != 2){
            file.close();
            emit ParseOver(false);
            return;
        }
    }else if (data[0] == 'f' && data[1] == ' ') {
      if (!ParseFace(data)) {
        file.close();
        emit ParseOver(false);
        return;
      }
    }
  }

  file.close();

  for (int i = 0; i < data_.size() / 8; ++i) {
      indices_.emplaceBack(i);
  }

  ChangeFilename();
  emit ParseOver(true);
}

template<typename Coordinatable>
size_t ObjParser::PushPoint(QByteArray &data, Coordinatable &target) {
  target.emplaceBack();
  auto cstr = data.data();
  size_t size = 0, sizeline_counter = 0;
  while (*cstr != EOF && *cstr != '\n') {
      while (!(IsNumber(*cstr))){
          ++cstr;
      }
      while (IsNumber(*(cstr + size))){
          ++size;
      }

      try{
          target.back()[sizeline_counter] = std::stof(cstr);
      }catch(...){
          return SIZE_MAX;
      }

    cstr += size;
    size = 0;
    ++sizeline_counter;
  }
  return sizeline_counter;
}

bool ObjParser::ParseFace(QByteArray &data) {
    auto cstr = data.data();
    size_t data_size = data.size();
    size_t index = 0;

    while(*cstr != EOF && *cstr != '\n'){
        SkipUntilNextDigit(index, data_size, cstr);
        if(index >= data_size || !ToVerticeData(cstr, tmp_vertex_)){
            return false;
        }

        SkipUntilNextFace(index, data_size, cstr);
        if(index >= data_size || !ToVerticeData(cstr, tmp_texture_)){
            return false;
        }

        SkipUntilNextFace(index, data_size, cstr);
        if(index >= data_size || !ToVerticeData(cstr, tmp_normal_)){
            return false;
        }
    }

    return true;
}

void ObjParser::AddZeros()
{
    tmp_vertex_.push_back({0,0,0});
    tmp_texture_.push_back({0,0});
    tmp_normal_.push_back({0,0,0});
}

void ObjParser::Clear()
{
    data_.clear();
    indices_.clear();
    tmp_vertex_.clear();
    tmp_texture_.clear();
    tmp_normal_.clear();
}


void ObjParser::SkipUntilNextDigit(size_t &index, size_t data_size, char *&data)
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

void ObjParser::SkipUntilNextFace(size_t &index, size_t data_size, char *&data)
{
    while (index < data_size && *data != '/'){
        ++data;
        ++index;
    }
    ++data;
    ++index;
}

bool ObjParser::IsNumber(char c)
{
    return std::isdigit(c) || c == '.' || c == '-' || c == '+';
}



void ObjParser::ChangeFilename() noexcept {
  filename_ = filename_.mid(filename_.lastIndexOf("/") + 1).chopped(4) + "\n" +
              "Vertexes: " + QString::number(tmp_vertex_.size() / 3) +
          " Edges: " + QString::number(indices_.size() / 2);
}

template<typename Coordinatable>
bool ObjParser::ToVerticeData(char *&data, Coordinatable &from)
{
    short size = 0;
    while(IsNumber(*(data + size))){
        ++size;
    }
    int ind = std::stoi(data);
    data += size;
    size = 0;
    if(ind >= from.size()){
        return false;
    }
    if(ind < 0) {
        ind += from.size();
    };
    data_.emplaceBack(from[ind].x);
    data_.emplaceBack(from[ind].y);

    if constexpr(std::is_same_v<Coordinatable, QVector<Vertex>>){
        data_.emplaceBack(from[ind].z);
    }
    return true;
}

}  // namespace s21
