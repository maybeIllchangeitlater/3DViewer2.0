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

  for (int i = 0; i < data_.size() / ear_cutter_.GetObjectPropertiesCount(); ++i) {
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

  while (!LineOver(*cstr)) {
      while (!(IsNumber(*cstr)) && !LineOver(*cstr)){
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
    ear_cutter_.Clear();
    auto cstr = data.data();
    size_t data_size = data.size();
    size_t index = 0;

    if(face_type_ == UNKNOWN){
        FigureOutFaceType(data_size, cstr);
    }

    while(!LineOver(*cstr)){
        SkipUntilNextDigit(index, data_size, cstr);
        if(index >= data_size || !ToVerticeData(cstr, tmp_vertex_)){
            return false;
        }

        if(face_type_ == FULL){
            SkipUntilNextFace(index, data_size, cstr);
            if(index >= data_size || !ToVerticeData(cstr, tmp_texture_)){
                return false;
            }
        }

        if(face_type_ != VERTICE_ONLY){
            SkipUntilNextFace(index, data_size, cstr);
            if(index >= data_size || !ToVerticeData(cstr, tmp_normal_)){
                return false;
            }
        }
    }

    std::vector<float> triangulated = ear_cutter_.CutEars();
    for(const auto&v : triangulated){
        data_.emplaceBack(v);
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
    while (index < data_size && *data != '/' && !std::isspace(*data)){
        ++data;
        ++index;
    };
    while(*data == '/'){
        ++data;
        ++index;
    }
}

void s21::ObjParser::FigureOutFaceType(size_t data_size, char *data)
{
    short slash_counter = 0;
    for(size_t i = 0; i < data_size; ++i){
        if(*(data++) == '/'){
            ++slash_counter;
            if(*data == '/'){
                ++slash_counter;
            }
            break;
        }
    }
    face_type_ = !slash_counter
            ? VERTICE_ONLY
            : slash_counter == 1
                ? FULL
                : VERTICES_NORMALES;
    ear_cutter_.GetObjectPropertiesCount() -= face_type_ == VERTICE_ONLY
            ? (TEXTURE_PROPERTIES_SIZE + NORMALE_PROPERTIES_SIZE)
            : face_type_ == VERTICES_NORMALES
                ? TEXTURE_PROPERTIES_SIZE
                : 0;
}

 bool ObjParser::IsNumber(char c)
{
     return std::isdigit(c) || c == '.' || c == '-' || c == '+';
 }

 bool ObjParser::LineOver(char c)
 {
    return c == EOF || c == '\n';
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
    ear_cutter_.GetPolygon().emplace_back(from[ind].x);
    ear_cutter_.GetPolygon().emplace_back(from[ind].y);

    if constexpr(std::is_same_v<Coordinatable, QVector<Vertex>>){
        ear_cutter_.GetPolygon().emplace_back(from[ind].z);
    }
    return true;
}

}  // namespace s21
