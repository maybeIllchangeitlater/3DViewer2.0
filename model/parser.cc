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
  ParseFlags(file);
  AddZeros();

  while (!file.atEnd()) {
    QByteArray data(file.readLine());
    if (data[0] == 'v' && data[1] == ' ') {
      if (PushPoint(data, tmp_vertex_) != VERTEX_PROPERTIES_SIZE) {
        file.close();
        emit ParseOver(false);
        return;
      }
    } else if (data[0] == 'v' && data[1] == 'n'){
        if(PushPoint(data, tmp_normal_) != NORMALE_PROPERTIES_SIZE){
            file.close();
            emit ParseOver(false);
            return;
        }
    } else if(data[0] == 'v' && data[1] == 't'){
        if(PushPoint(data, tmp_texture_) != TEXTURE_PROPERTIES_SIZE){
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

  for (int i = 0; i < data_.size() / object_properties_count_; ++i) {
      indices_.emplaceBack(i);
  }

  ChangeFilename();
  emit ParseOver(true);
}

void ObjParser::ParseFlags(QFile &file)
{
    while (!file.atEnd() && !(has_textures_ && has_normales_)) {
      QByteArray data(file.readLine());
      if (data[0] == 'v' && data[1] == 'n') {
          has_normales_ = true;
      }else if(data[0] == 'v' && data[1] == 't'){
           has_textures_ = true;
      }
    }
    if(!has_normales_){
        object_properties_count_ -= NORMALE_PROPERTIES_SIZE;
    }
    if(!has_textures_){
        object_properties_count_ -= TEXTURE_PROPERTIES_SIZE;
    }
    file.seek(0);

}

template<typename Coordinatable>
size_t ObjParser::PushPoint(QByteArray &data, Coordinatable &target) {
  target.emplaceBack();
  auto cstr = data.data();
  size_t size = 0, sizeline_counter = 0;

  while (!LineOver(*cstr)) {
      while (!LineOver(*cstr) && !(IsNumber(*cstr))){
          ++cstr;
      }
      while (IsNumber(*(cstr + size))){
          ++size;
      }
      if(size){
          target.back()[sizeline_counter] = std::stof(cstr);
      }else{
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
    size_t counter = 0;
    QVector<float> first_vertice;
    QVector<float> first_triangle_last_vertice;

try{
    while(!LineOver(*cstr)){
        tmp_vertices_.clear();
        SkipUntilNextDigit(cstr);
        if(LineOver(*cstr) || !ToVerticeData(cstr, tmp_vertex_)){
            return false;
        }

        SkipUntilNextFace(cstr);
        if(CheckTexture(cstr)){
            if(LineOver(*cstr) || !ToVerticeData(cstr, tmp_texture_)){
                return false;
            }
        }
        SkipUntilNextFace(cstr);
        if(CheckNormale(cstr)){
            if(LineOver(*cstr) || !ToVerticeData(cstr, tmp_normal_)){
                return false;
            }
        }
        FakeTriangulate(first_vertice, first_triangle_last_vertice, counter);
    }
}catch(...){
    return false;
}
    if(counter < 3){
        data_ += first_vertice;
    }
    return true;
}

void ObjParser::AddZeros()
{
    tmp_vertex_.emplaceBack();
    tmp_texture_.emplaceBack();
    tmp_normal_.emplaceBack();
}

void ObjParser::Clear()
{
    has_normales_ = false;
    has_textures_ = false;
    object_properties_count_ = DEFAULT_OBJECT_PROPERTIES_COUNT;
    data_.clear();
    indices_.clear();
    tmp_vertex_.clear();
    tmp_texture_.clear();
    tmp_normal_.clear();
}


void ObjParser::SkipUntilNextDigit(char *&data) noexcept
{
    while (!LineOver(*data) && !std::isspace(*data)) {
      ++data;
    }
    while (!LineOver(*data) && !(std::isdigit(*data))) {
      ++data;
    }
}

void ObjParser::SkipUntilNextFace(char *&data) noexcept
{
    while (!LineOver(*data) && *data != '/' && !std::isspace(*data)){
        ++data;
    };
}

bool ObjParser::CheckTexture(char *&data)
{
    if(!has_textures_){
        return false;
    }
    if(*data != '/' || *(data + 1) == '/'){
        for(short i = 0; i < TEXTURE_PROPERTIES_SIZE; ++i){
            tmp_vertices_.emplace_back();
        }
        return false;
    }
    ++data;
    return true;
}

bool ObjParser::CheckNormale(char *&data)
{
    if(!has_normales_){
        return false;
    }
    if(std::isspace(*data)){
        for(short i = 0; i < NORMALE_PROPERTIES_SIZE; ++i){
            tmp_vertices_.emplace_back();
        }
        return false;
    }
    while(*data == '/'){
        ++data;
    }
    return true;
}

void ObjParser::FakeTriangulate(QVector<float> &first, QVector<float> &middle, size_t& counter)
{
    if(counter < 3){
        if(!counter){
            data_ += tmp_vertices_;
            first = std::move(tmp_vertices_);
        }else if(counter == 2){
            data_ += tmp_vertices_;
            middle = std::move(tmp_vertices_);
        }else{
            data_ += tmp_vertices_;
        }
        ++counter;
    }else{
        data_ += first;
        data_ += middle;
        data_ += tmp_vertices_;
        middle = std::move(tmp_vertices_);
    }
}


 bool ObjParser::IsNumber(char c) noexcept
{
     return std::isdigit(c) || c == '.' || c == '-' || c == '+';
 }

 bool ObjParser::LineOver(char c) noexcept
 {
    return c == EOF || c == '\n' || c == '\r' || c == '\0';
 }

void ObjParser::ChangeFilename() {
  filename_ = filename_.mid(filename_.lastIndexOf("/") + 1).chopped(4) + "\n" +
              "Vertexes: " + QString::number(tmp_vertex_.size() / 3) +
          " Edges: " + QString::number(indices_.size() / 2);
}

template<typename Coordinatable>
bool ObjParser::ToVerticeData(char *&data, Coordinatable &from)
{
    short size = 0;
    while(!LineOver(*(data + size)) && IsNumber(*(data + size))){
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
    tmp_vertices_.emplace_back(from[ind].x);
    tmp_vertices_.emplace_back(from[ind].y);

    if constexpr(std::is_same_v<Coordinatable, QVector<Vertex>>){
        tmp_vertices_.emplace_back(from[ind].z);
    }
    return true;
}

}  // namespace s21
